// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb__DOT__clk;
    CData/*0:0*/ tb__DOT__reset;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*18:0*/ tb__DOT__vector_out;
    IData/*18:0*/ tb__DOT__dut__DOT__sum;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> tb__DOT__vector_a;
    VlUnpacked<CData/*7:0*/, 8> tb__DOT__vector_b;
    VlUnpacked<SData/*15:0*/, 8> tb__DOT__dut__DOT__temp;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hacbda2e7__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
