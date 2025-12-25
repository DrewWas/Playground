#include <stdint.h>
#include <string.h>

/* ---------- Configuration ---------- */

#define MAX_LINE_LEN      32    // max chars per line (excluding '\n')
#define LINE_QUEUE_DEPTH   4    // max number of complete lines buffered

/* ---------- Line Types ---------- */

typedef struct {
    char    data[MAX_LINE_LEN + 1];  // +1 for '\0'
    uint8_t len;                     // number of valid chars (no '\0')
} line_t;

typedef struct {
    line_t  buf[LINE_QUEUE_DEPTH];
    uint8_t head;     // write index
    uint8_t tail;     // read index
    uint8_t count;    // number of lines stored
} line_queue_t;

typedef struct {
    char    cur_buf[MAX_LINE_LEN + 1];
    uint8_t cur_len;
    uint8_t discarding;   // non-zero if currently discarding an overlong line
} line_assembler_t;

/* ---------- Module-Scope State ---------- */

static line_queue_t      g_line_q;
static line_assembler_t  g_assembler;

/* ---------- Internal Helpers (you decide behavior) ---------- */

static void line_queue_init(line_queue_t *q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;

}
static int  line_queue_push(line_queue_t *q, const char *data, uint8_t len) {
    if (q->count >= LINE_QUEUE_DEPTH) {
        return 0;
    }

    line_t *slot = &q->buf[q->head];

    if (len > MAX_LINE_LEN) len = MAX_LINE_LEN;

    for (int i = 0; i < len; i++) {
        slot->data[i] = data[i];
    }
    slot->data[len] = '\0';
    slot->len = len;

    q->head = (q->head + 1) % LINE_QUEUE_DEPTH;
    q->count++;

    return 1;
}

static int  line_queue_pop(line_queue_t *q, line_t *out) {
    if (q->count == 0) {
        return 0;
    }

    memcpy(out, &q->buf[q->tail], sizeof(line_t));

    q->tail = (q->tail + 1) % LINE_QUEUE_DEPTH;
    q->count--;

    return 1;
}

static void assembler_init(line_assembler_t *a) {
    a->cur_len = 0;
    a->discarding = 0;
}

static void assembler_process_byte(line_assembler_t *a, line_queue_t *q, uint8_t byte) {
    if (byte == '\n') {
        if (!a->discarding && a->cur_len > 0) {
            line_queue_push(q, a->cur_buf, a->cur_len);
        }
        assembler_init(a);
        return;
    } 
    if (a->discarding) {
        return;
    } 
    if (a->cur_len < MAX_LINE_LEN) {
        a->cur_buf[a->cur_len] = (char)byte;
        a->cur_len++;
    } else {
        a->discarding = 1;
    }
 
}

/* ---------- Public API ---------- */

/* Call once at startup */
void line_input_init(void)
{
    line_queue_init(&g_line_q);
    assembler_init(&g_assembler);
}

/* Called from UART RX ISR for each received byte */
void uart_rx_isr_byte(uint8_t byte)
{
    assembler_process_byte(&g_assembler, &g_line_q, byte);
}

/*
 * Called from main loop to get next complete line if available.
 * Returns 1 if a line was copied out, 0 if no line available.
 * dst must have space for MAX_LINE_LEN+1 bytes.
 */
int get_next_line(char *dst, uint8_t *len)
{
    line_t line;
    if (!line_queue_pop(&g_line_q, &line)) {
        return 0;
    }

    // you decide how to copy / null-terminate
    // e.g., for (i = 0; i < line.len; ++i) ...
    // set *len appropriately
    memcpy(dst, line.data, line.len);
    dst[line.len] = '\0';
    *len = line.len;

    return 1;
}
