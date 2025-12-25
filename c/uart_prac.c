#include <stdint.h>

/* ---------- Configuration ---------- */

#define UART_RX_BUF_SIZE 64

/* ---------- Ring Buffer Type ---------- */

typedef struct {
    uint8_t buf[UART_RX_BUF_SIZE];
    uint8_t head;   // write index
    uint8_t tail;   // read index
    uint8_t count;  // number of bytes stored
} uart_rx_buffer_t;

/* ---------- Module-Scope State ---------- */

static uart_rx_buffer_t g_uart_rx_buf;

/* ---------- Internal Helpers (if needed) ---------- */

static void uart_rx_buffer_init(uart_rx_buffer_t *rb)
{
    /* TODO: initialize head, tail, count */
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

static int uart_rx_buffer_push(uart_rx_buffer_t *rb, uint8_t byte)
{
    /* TODO:
     *  - If buffer full, return 0 (drop byte)
     *  - Else store byte at head, advance head, increment count
     *  - Return 1 on success
     */
     if (rb->count == UART_RX_BUF_SIZE) {
       return 0;
     } else {
        rb->buf[rb->head] = byte;
        rb->head = (rb->head + 1) % UART_RX_BUF_SIZE;
        rb->count++;
        return 1;
     }
}

static int uart_rx_buffer_pop(uart_rx_buffer_t *rb, uint8_t *out_byte)
{
    /* TODO:
     *  - If buffer empty, return 0
     *  - Else read byte at tail into *out_byte,
     *    advance tail, decrement count
     *  - Return 1 on success
     */
     if (rb->count == 0) {
         return 0;
     } else {
        *out_byte = rb->buf[rb->tail]; 
        rb->tail= (rb->tail+ 1) % UART_RX_BUF_SIZE;
        rb->count--;   
        return 1;
     }
}



/* ---------- Public API ---------- */

/* Call once at startup */
void uart_buffer_init(void)
{
    /* TODO: call uart_rx_buffer_init(&g_uart_rx_buf); */
    uart_rx_buffer_init(&g_uart_rx_buf);
}

/*
 * Called from UART RX ISR for each received byte.
 * Must be very fast and non-blocking.
 */
void uart_rx_isr_byte(uint8_t byte)
{
    /* TODO: call uart_rx_buffer_push(&g_uart_rx_buf, byte); */
    uart_rx_buffer_push(&g_uart_rx_buf, byte);
}

/*
 * Called from main loop to read one byte if available.
 * Returns 1 if a byte was read, 0 if buffer empty.
 */
int uart_read_byte(uint8_t *out)
{
    /* TODO: call uart_rx_buffer_pop(&g_uart_rx_buf, out); */
    return uart_rx_buffer_pop(&g_uart_rx_buf, out);
}




