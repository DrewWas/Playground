
#include <cstdint>
#include <cstddef>
#include <array>
#include <iostream>

class RingBuffer {
   
    private: 
        // Buffer can store 64 elements each of 16 bits (128 bytes total) 
        static constexpr size_t CAPACITY = 64;

        // Buffer + Buffer variables 
        std::array<int16_t, CAPACITY> buffer{}; 
        size_t write_pntr  = 0;
        size_t read_pntr   = 0;
        size_t buffer_size = 0;

    public:
        // No need for an index because ring buffers are FIFOs
        bool write_to_buffer(int16_t data) {
            // Buffer full
            if (buffer_size == CAPACITY) {
                std::cout << "Buffer full!\n";
            } else { 
                // Return if write was successful
                buffer[write_pntr] = data;
                write_pntr = (write_pntr + 1) % CAPACITY;
                buffer_size++;

                return true; 
            }

            return false;
        }

        int16_t read_from_buffer() {
            // Return if read was successful
            if (buffer_size == 0) {
                return 0;
            }
            int16_t output = buffer[read_pntr];
            std::cout << output; 
            std::cout << "\n";
            read_pntr = (read_pntr + 1) % CAPACITY;
            --buffer_size;

            return output; 
        }

        void clear_buffer() {
            // Just reset the buffer pointers, don't need to zero out the actual data 
            write_pntr = 0;
            read_pntr = 0;
            buffer_size = 0;
        } 

};


int main() {

    RingBuffer rb;

    rb.write_to_buffer(42);
    rb.write_to_buffer(67);
    rb.write_to_buffer(69);
    rb.write_to_buffer(1);
    rb.read_from_buffer();
    rb.read_from_buffer();
    rb.read_from_buffer();
    rb.read_from_buffer();
    rb.read_from_buffer();
    rb.read_from_buffer();
    rb.write_to_buffer(0);
    rb.write_to_buffer(1000);
    rb.read_from_buffer();
    rb.read_from_buffer();

    return 0;

}





