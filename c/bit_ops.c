#include <stdint.h>
#include <stdbool.h>





uint32_t set_bit(uint32_t x, int n) {
    if (n >= 32) return x;
    return (x | (1u << n));
}


uint32_t clear_bit(uint32_t x, int n) {
    if (n >= 32) return x;
    return (x & ~(1u << n));
} 


uint32_t toggle_bit(uint32_t x, int n) {
    if (n >= 32) return x;
    return (x ^ (1u << n));
} 


bool test_bit(uint32_t x, int n) {
    if (n >= 32) return false;
    return (x >> n) % 2;
} 


