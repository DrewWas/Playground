
#include <cstdint>
#include <cstddef>
#include <array>
#include <iostream>

class RingBuffer {
   
    private: 
        // Buffer can store 64 bytes
        static constexpr size_t CAPACITY = 64;

        // Buffer + Buffer variables 
        std::array<int16_t, CAPACITY> buffer{}; 
        size_t write_pntr  = 0;
        size_t read_pntr   = 0;
        size_t buffer_size = 0;


    public:
        // No need for an index because ring buffers are FIFOs
        bool write_to_buffer(int16_t data) {
            // Return if write was successful
            buffer[write_pntr] = data;
            write_pntr += 1;
            buffer_size += 1;

            return buffer_size < CAPACITY;
        }

        int16_t read_from_buffer() {
            // Return if read was successful
            std::cout << buffer[read_pntr];
            std::cout << "\n";
            read_pntr += 1;


            return 0; 
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
    rb.read_from_buffer();

    rb.write_to_buffer(67);
    rb.read_from_buffer();

    rb.write_to_buffer(69);
    rb.read_from_buffer();

    rb.write_to_buffer(1);
    rb.read_from_buffer();

    return 0;

}





