// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vand.h for the primary calling header

#ifndef VERILATED_VAND___024ROOT_H_
#define VERILATED_VAND___024ROOT_H_  // guard

#include "verilated.h"


class Vand__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vand___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(input_1,0,0);
    VL_IN8(input_2,0,0);
    VL_OUT8(out,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vand__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vand___024root(Vand__Syms* symsp, const char* v__name);
    ~Vand___024root();
    VL_UNCOPYABLE(Vand___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
