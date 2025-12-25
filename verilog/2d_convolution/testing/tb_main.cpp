#include <verilated.h>
#include "Vmain.h"

int main(int argc, char** argv) {

    Verilated::commandArgs(argc, argv);
    Vtb* tb = new Vmain;

    while (!Verilated::gotFinish()) {
        tb->eval();
        Verilated::timeInc(1);
    }

    delete tb;
    return 0;
}



