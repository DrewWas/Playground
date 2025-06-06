#include <iostream>
#include "Vand.h"
#include "verilated.h"

int main(int argc, char**argv) {

    Verilated::commandArgs(argc, argv);

    Vand* uut = new Vand;

    for (int i = 0; i < 4; i++) {
        uut->input_1 = (i >> 1) & 1;
        uut->input_2 = i & 1;

        uut->eval();

        std::cout << "input_1 = " << (int)uut->input_1 << std::endl;
        std::cout << "input_2 = " << (int)uut->input_2 << std::endl;
        std::cout << "out = " << (int)uut->out << std::endl;
        std::cout << std::endl;

    }


    delete uut;
    return 0;

}
