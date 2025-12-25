#include <stdint.h>

#define MAX_PAYLOAD_LEN 16

typedef enum {
    PARSER_STATE_WAIT_START = 0,
    PARSER_STATE_CMD,
    PARSER_STATE_LEN,
    PARSER_STATE_PAYLOAD,
    PARSER_STATE_CHECKSUM
} parser_state_t;

typedef struct {
    parser_state_t state;
    uint8_t        cmd;
    uint8_t        len;
    uint8_t        bytes_received;
    uint8_t        payload[MAX_PAYLOAD_LEN];
    uint8_t        checksum_acc;
} frame_parser_t;

static frame_parser_t g_parser;


void parser_init(void)
{
    /* your code */
    g_parser.state = PARSER_STATE_WAIT_START;
    g_parser.cmd = 0;
    g_parser.len = 0;
    g_parser.bytes_received = 0;
    g_parser.checksum_acc = 0;
}

void uart_rx_isr_byte(uint8_t byte)
{
    switch (g_parser.state) {
        
        case PARSER_STATE_WAIT_START :
            if (byte == 0x55) {
                g_parser.state = PARSER_STATE_CMD;
                g_parser.checksum_acc   = 0;
                g_parser.bytes_received = 0;
            }
        break;

        case PARSER_STATE_CMD :
            g_parser.cmd = byte;
            g_parser.checksum_acc += byte;
            g_parser.state = PARSER_STATE_LEN;
        break;

        case PARSER_STATE_LEN :
            g_parser.len = byte;
            if (g_parser.len > MAX_PAYLOAD_LEN) {
                g_parser.state = PARSER_STATE_WAIT_START;
                break;
            }
            g_parser.bytes_received = 0;
            g_parser.checksum_acc += byte;
            g_parser.state = (g_parser.len == 0) 
                   ? PARSER_STATE_CHECKSUM
                   : PARSER_STATE_PAYLOAD;

            
        break;

        case PARSER_STATE_PAYLOAD :
            if (g_parser.bytes_received >= g_parser.len) {
                g_parser.state = PARSER_STATE_CHECKSUM;
                break;
            } else {
                g_parser.payload[g_parser.bytes_received++] = byte;
                g_parser.checksum_acc += byte;
            }
        break;

        case PARSER_STATE_CHECKSUM :
        if (g_parser.checksum_acc == byte) {
            handle_packet(g_parser.cmd, g_parser.payload, g_parser.len);
        }
        parser_init();
        break;

    }

}

/* Provided elsewhere */
void handle_packet(uint8_t cmd, const uint8_t *payload, uint8_t len);



