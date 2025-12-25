#include <stdint.h>

#define BTN_EVENT_QUEUE_DEPTH 8
#define BTN_DEBOUNCE_MS       20

typedef struct {
    uint8_t q[BTN_EVENT_QUEUE_DEPTH];  // each entry: 0 = released, 1 = pressed
    uint8_t head;   // write index
    uint8_t tail;   // read index
    uint8_t count;  // number of events stored
} button_event_queue_t;

typedef struct {
    uint8_t stable_state;     // last debounced state (0/1)
    uint8_t last_sample;      // last raw sampled state
    uint8_t stable_ms;        // how long last_sample has been stable (in ms)
} button_debouncer_t;

static button_event_queue_t g_btn_q;
static button_debouncer_t   g_btn_db;

/* Call once at startup */
void button_init(void)
{
    /* your code */
    g_btn_q.head = 0;
    g_btn_q.tail = 0;
    g_btn_q.count = 0;
    g_btn_db.stable_ms = 0;
}

/* Called every 1 ms from a timer ISR */
void systick_isr(void)
{
    /* your code */
    if (g_btn_db.stable_state != g_btn_db.last_sample) {
        g_btn_db.stable_ms = 0;
        return;
    }

    g_btn_db.stable_state = gpio_read_button();
    g_btn_db.last_sample = g_btn_db.stable_state;
    g_btn_db.stable_ms++;

}

/* Called from main loop to get next debounced button event.
 * Returns 1 if an event is available, 0 otherwise.
 */
int button_get_event(uint8_t *pressed)
{
    /* your code */
    return g_btn_db.stable_ms > 20;
}

/* Provided elsewhere */
uint8_t gpio_read_button(void);  // returns 0 or 1


