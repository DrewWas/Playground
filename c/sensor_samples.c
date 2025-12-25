#include <stdint.h>

#define ADC_SAMPLE_BUF_SIZE 128

typedef struct {
    int16_t buf[ADC_SAMPLE_BUF_SIZE];
    uint16_t head;      // write index
    uint16_t tail;      // read index
    uint16_t count;     // number of valid samples in buffer
} adc_ring_buffer_t;

static adc_ring_buffer_t g_adc_buf;

/* Init function, called once at startup */
void adc_buffer_init(void)
{
    /* your code */
    g_adc_buf.count = 0;
    g_adc_buf.head = 0;
    g_adc_buf.tail = 0;

}

/* Called from ISR context when a block of samples is ready */
void adc_block_ready_isr(const int16_t *samples, uint8_t count)
{
    /* your code */
    for (int i = 0; i < count && g_adc_buf.count < ADC_SAMPLE_BUF_SIZE; i++) {
        g_adc_buf.buf[g_adc_buf.head] = samples[i];
        g_adc_buf.head = (g_adc_buf.head + 1) % ADC_SAMPLE_BUF_SIZE;
        g_adc_buf.count++;
    }
    

}

/*
 * Called from main loop.
 * Returns 1 and writes sample into *out_sample if available,
 * returns 0 if buffer empty.
 */
int adc_get_sample(int16_t *out_sample)
{
    /* your code */
    if (g_adc_buf.count == 0) {
        return 0;
    } 

    *out_sample = g_adc_buf.buf[g_adc_buf.tail];
    g_adc_buf.tail = (g_adc_buf.tail + 1) % ADC_SAMPLE_BUF_SIZE;
    g_adc_buf.count--;
    return 1;
}



