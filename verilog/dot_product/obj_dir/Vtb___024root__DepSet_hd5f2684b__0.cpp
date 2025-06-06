// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb__DOT__test_num;
    tb__DOT__test_num = 0;
    IData/*18:0*/ tb__DOT__expected;
    tb__DOT__expected = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a0;
    __Vtask_tb__DOT__load_vectors__2__a0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a1;
    __Vtask_tb__DOT__load_vectors__2__a1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a2;
    __Vtask_tb__DOT__load_vectors__2__a2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a3;
    __Vtask_tb__DOT__load_vectors__2__a3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a4;
    __Vtask_tb__DOT__load_vectors__2__a4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a5;
    __Vtask_tb__DOT__load_vectors__2__a5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a6;
    __Vtask_tb__DOT__load_vectors__2__a6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__a7;
    __Vtask_tb__DOT__load_vectors__2__a7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b0;
    __Vtask_tb__DOT__load_vectors__2__b0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b1;
    __Vtask_tb__DOT__load_vectors__2__b1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b2;
    __Vtask_tb__DOT__load_vectors__2__b2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b3;
    __Vtask_tb__DOT__load_vectors__2__b3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b4;
    __Vtask_tb__DOT__load_vectors__2__b4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b5;
    __Vtask_tb__DOT__load_vectors__2__b5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b6;
    __Vtask_tb__DOT__load_vectors__2__b6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__2__b7;
    __Vtask_tb__DOT__load_vectors__2__b7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a0;
    __Vtask_tb__DOT__load_vectors__4__a0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a1;
    __Vtask_tb__DOT__load_vectors__4__a1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a2;
    __Vtask_tb__DOT__load_vectors__4__a2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a3;
    __Vtask_tb__DOT__load_vectors__4__a3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a4;
    __Vtask_tb__DOT__load_vectors__4__a4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a5;
    __Vtask_tb__DOT__load_vectors__4__a5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a6;
    __Vtask_tb__DOT__load_vectors__4__a6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__a7;
    __Vtask_tb__DOT__load_vectors__4__a7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b0;
    __Vtask_tb__DOT__load_vectors__4__b0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b1;
    __Vtask_tb__DOT__load_vectors__4__b1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b2;
    __Vtask_tb__DOT__load_vectors__4__b2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b3;
    __Vtask_tb__DOT__load_vectors__4__b3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b4;
    __Vtask_tb__DOT__load_vectors__4__b4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b5;
    __Vtask_tb__DOT__load_vectors__4__b5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b6;
    __Vtask_tb__DOT__load_vectors__4__b6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__4__b7;
    __Vtask_tb__DOT__load_vectors__4__b7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a0;
    __Vtask_tb__DOT__load_vectors__6__a0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a1;
    __Vtask_tb__DOT__load_vectors__6__a1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a2;
    __Vtask_tb__DOT__load_vectors__6__a2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a3;
    __Vtask_tb__DOT__load_vectors__6__a3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a4;
    __Vtask_tb__DOT__load_vectors__6__a4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a5;
    __Vtask_tb__DOT__load_vectors__6__a5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a6;
    __Vtask_tb__DOT__load_vectors__6__a6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__a7;
    __Vtask_tb__DOT__load_vectors__6__a7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b0;
    __Vtask_tb__DOT__load_vectors__6__b0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b1;
    __Vtask_tb__DOT__load_vectors__6__b1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b2;
    __Vtask_tb__DOT__load_vectors__6__b2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b3;
    __Vtask_tb__DOT__load_vectors__6__b3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b4;
    __Vtask_tb__DOT__load_vectors__6__b4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b5;
    __Vtask_tb__DOT__load_vectors__6__b5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b6;
    __Vtask_tb__DOT__load_vectors__6__b6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__6__b7;
    __Vtask_tb__DOT__load_vectors__6__b7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a0;
    __Vtask_tb__DOT__load_vectors__8__a0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a1;
    __Vtask_tb__DOT__load_vectors__8__a1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a2;
    __Vtask_tb__DOT__load_vectors__8__a2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a3;
    __Vtask_tb__DOT__load_vectors__8__a3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a4;
    __Vtask_tb__DOT__load_vectors__8__a4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a5;
    __Vtask_tb__DOT__load_vectors__8__a5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a6;
    __Vtask_tb__DOT__load_vectors__8__a6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__a7;
    __Vtask_tb__DOT__load_vectors__8__a7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b0;
    __Vtask_tb__DOT__load_vectors__8__b0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b1;
    __Vtask_tb__DOT__load_vectors__8__b1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b2;
    __Vtask_tb__DOT__load_vectors__8__b2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b3;
    __Vtask_tb__DOT__load_vectors__8__b3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b4;
    __Vtask_tb__DOT__load_vectors__8__b4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b5;
    __Vtask_tb__DOT__load_vectors__8__b5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b6;
    __Vtask_tb__DOT__load_vectors__8__b6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__8__b7;
    __Vtask_tb__DOT__load_vectors__8__b7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a0;
    __Vtask_tb__DOT__load_vectors__10__a0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a1;
    __Vtask_tb__DOT__load_vectors__10__a1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a2;
    __Vtask_tb__DOT__load_vectors__10__a2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a3;
    __Vtask_tb__DOT__load_vectors__10__a3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a4;
    __Vtask_tb__DOT__load_vectors__10__a4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a5;
    __Vtask_tb__DOT__load_vectors__10__a5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a6;
    __Vtask_tb__DOT__load_vectors__10__a6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__a7;
    __Vtask_tb__DOT__load_vectors__10__a7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b0;
    __Vtask_tb__DOT__load_vectors__10__b0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b1;
    __Vtask_tb__DOT__load_vectors__10__b1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b2;
    __Vtask_tb__DOT__load_vectors__10__b2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b3;
    __Vtask_tb__DOT__load_vectors__10__b3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b4;
    __Vtask_tb__DOT__load_vectors__10__b4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b5;
    __Vtask_tb__DOT__load_vectors__10__b5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b6;
    __Vtask_tb__DOT__load_vectors__10__b6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__10__b7;
    __Vtask_tb__DOT__load_vectors__10__b7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a0;
    __Vtask_tb__DOT__load_vectors__12__a0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a1;
    __Vtask_tb__DOT__load_vectors__12__a1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a2;
    __Vtask_tb__DOT__load_vectors__12__a2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a3;
    __Vtask_tb__DOT__load_vectors__12__a3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a4;
    __Vtask_tb__DOT__load_vectors__12__a4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a5;
    __Vtask_tb__DOT__load_vectors__12__a5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a6;
    __Vtask_tb__DOT__load_vectors__12__a6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__a7;
    __Vtask_tb__DOT__load_vectors__12__a7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b0;
    __Vtask_tb__DOT__load_vectors__12__b0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b1;
    __Vtask_tb__DOT__load_vectors__12__b1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b2;
    __Vtask_tb__DOT__load_vectors__12__b2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b3;
    __Vtask_tb__DOT__load_vectors__12__b3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b4;
    __Vtask_tb__DOT__load_vectors__12__b4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b5;
    __Vtask_tb__DOT__load_vectors__12__b5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b6;
    __Vtask_tb__DOT__load_vectors__12__b6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__12__b7;
    __Vtask_tb__DOT__load_vectors__12__b7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a0;
    __Vtask_tb__DOT__load_vectors__14__a0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a1;
    __Vtask_tb__DOT__load_vectors__14__a1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a2;
    __Vtask_tb__DOT__load_vectors__14__a2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a3;
    __Vtask_tb__DOT__load_vectors__14__a3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a4;
    __Vtask_tb__DOT__load_vectors__14__a4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a5;
    __Vtask_tb__DOT__load_vectors__14__a5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a6;
    __Vtask_tb__DOT__load_vectors__14__a6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__a7;
    __Vtask_tb__DOT__load_vectors__14__a7 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b0;
    __Vtask_tb__DOT__load_vectors__14__b0 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b1;
    __Vtask_tb__DOT__load_vectors__14__b1 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b2;
    __Vtask_tb__DOT__load_vectors__14__b2 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b3;
    __Vtask_tb__DOT__load_vectors__14__b3 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b4;
    __Vtask_tb__DOT__load_vectors__14__b4 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b5;
    __Vtask_tb__DOT__load_vectors__14__b5 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b6;
    __Vtask_tb__DOT__load_vectors__14__b6 = 0;
    CData/*7:0*/ __Vtask_tb__DOT__load_vectors__14__b7;
    __Vtask_tb__DOT__load_vectors__14__b7 = 0;
    // Body
    tb__DOT__test_num = 1U;
    VL_WRITEF_NX("\nTest #1: All Zeros\n",0);
    vlSelfRef.tb__DOT__vector_a[0U] = 0U;
    vlSelfRef.tb__DOT__vector_a[1U] = 0U;
    vlSelfRef.tb__DOT__vector_a[2U] = 0U;
    vlSelfRef.tb__DOT__vector_a[3U] = 0U;
    vlSelfRef.tb__DOT__vector_a[4U] = 0U;
    vlSelfRef.tb__DOT__vector_a[5U] = 0U;
    vlSelfRef.tb__DOT__vector_a[6U] = 0U;
    vlSelfRef.tb__DOT__vector_a[7U] = 0U;
    vlSelfRef.tb__DOT__vector_b[0U] = 0U;
    vlSelfRef.tb__DOT__vector_b[1U] = 0U;
    vlSelfRef.tb__DOT__vector_b[2U] = 0U;
    vlSelfRef.tb__DOT__vector_b[3U] = 0U;
    vlSelfRef.tb__DOT__vector_b[4U] = 0U;
    vlSelfRef.tb__DOT__vector_b[5U] = 0U;
    vlSelfRef.tb__DOT__vector_b[6U] = 0U;
    vlSelfRef.tb__DOT__vector_b[7U] = 0U;
    VL_WRITEF_NX("Vector A: [0, 0, 0, 0, 0, 0, 0, 0]\nVector B: [0, 0, 0, 0, 0, 0, 0, 0]\n",0);
    tb__DOT__expected = 0U;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         32);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    tb__DOT__test_num = 2U;
    VL_WRITEF_NX("Test #%0d: All 255s\n",0,32,tb__DOT__test_num);
    __Vtask_tb__DOT__load_vectors__2__b7 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__b6 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__b5 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__b4 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__b3 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__b2 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__b1 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__b0 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a7 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a6 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a5 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a4 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a3 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a2 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a1 = 0xffU;
    __Vtask_tb__DOT__load_vectors__2__a0 = 0xffU;
    vlSelfRef.tb__DOT__vector_a[0U] = __Vtask_tb__DOT__load_vectors__2__a0;
    vlSelfRef.tb__DOT__vector_a[1U] = __Vtask_tb__DOT__load_vectors__2__a1;
    vlSelfRef.tb__DOT__vector_a[2U] = __Vtask_tb__DOT__load_vectors__2__a2;
    vlSelfRef.tb__DOT__vector_a[3U] = __Vtask_tb__DOT__load_vectors__2__a3;
    vlSelfRef.tb__DOT__vector_a[4U] = __Vtask_tb__DOT__load_vectors__2__a4;
    vlSelfRef.tb__DOT__vector_a[5U] = __Vtask_tb__DOT__load_vectors__2__a5;
    vlSelfRef.tb__DOT__vector_a[6U] = __Vtask_tb__DOT__load_vectors__2__a6;
    vlSelfRef.tb__DOT__vector_a[7U] = __Vtask_tb__DOT__load_vectors__2__a7;
    vlSelfRef.tb__DOT__vector_b[0U] = __Vtask_tb__DOT__load_vectors__2__b0;
    vlSelfRef.tb__DOT__vector_b[1U] = __Vtask_tb__DOT__load_vectors__2__b1;
    vlSelfRef.tb__DOT__vector_b[2U] = __Vtask_tb__DOT__load_vectors__2__b2;
    vlSelfRef.tb__DOT__vector_b[3U] = __Vtask_tb__DOT__load_vectors__2__b3;
    vlSelfRef.tb__DOT__vector_b[4U] = __Vtask_tb__DOT__load_vectors__2__b4;
    vlSelfRef.tb__DOT__vector_b[5U] = __Vtask_tb__DOT__load_vectors__2__b5;
    vlSelfRef.tb__DOT__vector_b[6U] = __Vtask_tb__DOT__load_vectors__2__b6;
    vlSelfRef.tb__DOT__vector_b[7U] = __Vtask_tb__DOT__load_vectors__2__b7;
    VL_WRITEF_NX("Vector A: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\nVector B: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\n",0,
                 8,__Vtask_tb__DOT__load_vectors__2__a0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__a1),
                 8,__Vtask_tb__DOT__load_vectors__2__a2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__a3),
                 8,__Vtask_tb__DOT__load_vectors__2__a4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__a5),
                 8,__Vtask_tb__DOT__load_vectors__2__a6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__a7),
                 8,__Vtask_tb__DOT__load_vectors__2__b0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__b1),
                 8,__Vtask_tb__DOT__load_vectors__2__b2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__b3),
                 8,__Vtask_tb__DOT__load_vectors__2__b4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__b5),
                 8,__Vtask_tb__DOT__load_vectors__2__b6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__2__b7));
    tb__DOT__expected = 0x7f008U;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         43);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    tb__DOT__test_num = 3U;
    VL_WRITEF_NX("Test #%0d: Mismatch\n",0,32,tb__DOT__test_num);
    __Vtask_tb__DOT__load_vectors__4__b7 = 0xffU;
    __Vtask_tb__DOT__load_vectors__4__b6 = 0U;
    __Vtask_tb__DOT__load_vectors__4__b5 = 0xffU;
    __Vtask_tb__DOT__load_vectors__4__b4 = 0U;
    __Vtask_tb__DOT__load_vectors__4__b3 = 0xffU;
    __Vtask_tb__DOT__load_vectors__4__b2 = 0U;
    __Vtask_tb__DOT__load_vectors__4__b1 = 0xffU;
    __Vtask_tb__DOT__load_vectors__4__b0 = 0U;
    __Vtask_tb__DOT__load_vectors__4__a7 = 0U;
    __Vtask_tb__DOT__load_vectors__4__a6 = 0xffU;
    __Vtask_tb__DOT__load_vectors__4__a5 = 0U;
    __Vtask_tb__DOT__load_vectors__4__a4 = 0xffU;
    __Vtask_tb__DOT__load_vectors__4__a3 = 0U;
    __Vtask_tb__DOT__load_vectors__4__a2 = 0xffU;
    __Vtask_tb__DOT__load_vectors__4__a1 = 0U;
    __Vtask_tb__DOT__load_vectors__4__a0 = 0xffU;
    vlSelfRef.tb__DOT__vector_a[0U] = __Vtask_tb__DOT__load_vectors__4__a0;
    vlSelfRef.tb__DOT__vector_a[1U] = __Vtask_tb__DOT__load_vectors__4__a1;
    vlSelfRef.tb__DOT__vector_a[2U] = __Vtask_tb__DOT__load_vectors__4__a2;
    vlSelfRef.tb__DOT__vector_a[3U] = __Vtask_tb__DOT__load_vectors__4__a3;
    vlSelfRef.tb__DOT__vector_a[4U] = __Vtask_tb__DOT__load_vectors__4__a4;
    vlSelfRef.tb__DOT__vector_a[5U] = __Vtask_tb__DOT__load_vectors__4__a5;
    vlSelfRef.tb__DOT__vector_a[6U] = __Vtask_tb__DOT__load_vectors__4__a6;
    vlSelfRef.tb__DOT__vector_a[7U] = __Vtask_tb__DOT__load_vectors__4__a7;
    vlSelfRef.tb__DOT__vector_b[0U] = __Vtask_tb__DOT__load_vectors__4__b0;
    vlSelfRef.tb__DOT__vector_b[1U] = __Vtask_tb__DOT__load_vectors__4__b1;
    vlSelfRef.tb__DOT__vector_b[2U] = __Vtask_tb__DOT__load_vectors__4__b2;
    vlSelfRef.tb__DOT__vector_b[3U] = __Vtask_tb__DOT__load_vectors__4__b3;
    vlSelfRef.tb__DOT__vector_b[4U] = __Vtask_tb__DOT__load_vectors__4__b4;
    vlSelfRef.tb__DOT__vector_b[5U] = __Vtask_tb__DOT__load_vectors__4__b5;
    vlSelfRef.tb__DOT__vector_b[6U] = __Vtask_tb__DOT__load_vectors__4__b6;
    vlSelfRef.tb__DOT__vector_b[7U] = __Vtask_tb__DOT__load_vectors__4__b7;
    VL_WRITEF_NX("Vector A: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\nVector B: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\n",0,
                 8,__Vtask_tb__DOT__load_vectors__4__a0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__a1),
                 8,__Vtask_tb__DOT__load_vectors__4__a2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__a3),
                 8,__Vtask_tb__DOT__load_vectors__4__a4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__a5),
                 8,__Vtask_tb__DOT__load_vectors__4__a6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__a7),
                 8,__Vtask_tb__DOT__load_vectors__4__b0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__b1),
                 8,__Vtask_tb__DOT__load_vectors__4__b2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__b3),
                 8,__Vtask_tb__DOT__load_vectors__4__b4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__b5),
                 8,__Vtask_tb__DOT__load_vectors__4__b6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__4__b7));
    tb__DOT__expected = 0U;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         54);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    tb__DOT__test_num = 4U;
    VL_WRITEF_NX("Test #%0d: Half Zeros\n",0,32,tb__DOT__test_num);
    __Vtask_tb__DOT__load_vectors__6__b7 = 0U;
    __Vtask_tb__DOT__load_vectors__6__b6 = 0U;
    __Vtask_tb__DOT__load_vectors__6__b5 = 0U;
    __Vtask_tb__DOT__load_vectors__6__b4 = 0U;
    __Vtask_tb__DOT__load_vectors__6__b3 = 0U;
    __Vtask_tb__DOT__load_vectors__6__b2 = 0U;
    __Vtask_tb__DOT__load_vectors__6__b1 = 0U;
    __Vtask_tb__DOT__load_vectors__6__b0 = 0U;
    __Vtask_tb__DOT__load_vectors__6__a7 = 0x64U;
    __Vtask_tb__DOT__load_vectors__6__a6 = 0x64U;
    __Vtask_tb__DOT__load_vectors__6__a5 = 0x64U;
    __Vtask_tb__DOT__load_vectors__6__a4 = 0x64U;
    __Vtask_tb__DOT__load_vectors__6__a3 = 0x64U;
    __Vtask_tb__DOT__load_vectors__6__a2 = 0x64U;
    __Vtask_tb__DOT__load_vectors__6__a1 = 0x64U;
    __Vtask_tb__DOT__load_vectors__6__a0 = 0x64U;
    vlSelfRef.tb__DOT__vector_a[0U] = __Vtask_tb__DOT__load_vectors__6__a0;
    vlSelfRef.tb__DOT__vector_a[1U] = __Vtask_tb__DOT__load_vectors__6__a1;
    vlSelfRef.tb__DOT__vector_a[2U] = __Vtask_tb__DOT__load_vectors__6__a2;
    vlSelfRef.tb__DOT__vector_a[3U] = __Vtask_tb__DOT__load_vectors__6__a3;
    vlSelfRef.tb__DOT__vector_a[4U] = __Vtask_tb__DOT__load_vectors__6__a4;
    vlSelfRef.tb__DOT__vector_a[5U] = __Vtask_tb__DOT__load_vectors__6__a5;
    vlSelfRef.tb__DOT__vector_a[6U] = __Vtask_tb__DOT__load_vectors__6__a6;
    vlSelfRef.tb__DOT__vector_a[7U] = __Vtask_tb__DOT__load_vectors__6__a7;
    vlSelfRef.tb__DOT__vector_b[0U] = __Vtask_tb__DOT__load_vectors__6__b0;
    vlSelfRef.tb__DOT__vector_b[1U] = __Vtask_tb__DOT__load_vectors__6__b1;
    vlSelfRef.tb__DOT__vector_b[2U] = __Vtask_tb__DOT__load_vectors__6__b2;
    vlSelfRef.tb__DOT__vector_b[3U] = __Vtask_tb__DOT__load_vectors__6__b3;
    vlSelfRef.tb__DOT__vector_b[4U] = __Vtask_tb__DOT__load_vectors__6__b4;
    vlSelfRef.tb__DOT__vector_b[5U] = __Vtask_tb__DOT__load_vectors__6__b5;
    vlSelfRef.tb__DOT__vector_b[6U] = __Vtask_tb__DOT__load_vectors__6__b6;
    vlSelfRef.tb__DOT__vector_b[7U] = __Vtask_tb__DOT__load_vectors__6__b7;
    VL_WRITEF_NX("Vector A: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\nVector B: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\n",0,
                 8,__Vtask_tb__DOT__load_vectors__6__a0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__a1),
                 8,__Vtask_tb__DOT__load_vectors__6__a2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__a3),
                 8,__Vtask_tb__DOT__load_vectors__6__a4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__a5),
                 8,__Vtask_tb__DOT__load_vectors__6__a6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__a7),
                 8,__Vtask_tb__DOT__load_vectors__6__b0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__b1),
                 8,__Vtask_tb__DOT__load_vectors__6__b2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__b3),
                 8,__Vtask_tb__DOT__load_vectors__6__b4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__b5),
                 8,__Vtask_tb__DOT__load_vectors__6__b6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__6__b7));
    tb__DOT__expected = 0U;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         65);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    tb__DOT__test_num = 1U;
    VL_WRITEF_NX("Test #%0d: All Ones\n",0,32,tb__DOT__test_num);
    __Vtask_tb__DOT__load_vectors__8__b7 = 1U;
    __Vtask_tb__DOT__load_vectors__8__b6 = 1U;
    __Vtask_tb__DOT__load_vectors__8__b5 = 1U;
    __Vtask_tb__DOT__load_vectors__8__b4 = 1U;
    __Vtask_tb__DOT__load_vectors__8__b3 = 1U;
    __Vtask_tb__DOT__load_vectors__8__b2 = 1U;
    __Vtask_tb__DOT__load_vectors__8__b1 = 1U;
    __Vtask_tb__DOT__load_vectors__8__b0 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a7 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a6 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a5 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a4 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a3 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a2 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a1 = 1U;
    __Vtask_tb__DOT__load_vectors__8__a0 = 1U;
    vlSelfRef.tb__DOT__vector_a[0U] = __Vtask_tb__DOT__load_vectors__8__a0;
    vlSelfRef.tb__DOT__vector_a[1U] = __Vtask_tb__DOT__load_vectors__8__a1;
    vlSelfRef.tb__DOT__vector_a[2U] = __Vtask_tb__DOT__load_vectors__8__a2;
    vlSelfRef.tb__DOT__vector_a[3U] = __Vtask_tb__DOT__load_vectors__8__a3;
    vlSelfRef.tb__DOT__vector_a[4U] = __Vtask_tb__DOT__load_vectors__8__a4;
    vlSelfRef.tb__DOT__vector_a[5U] = __Vtask_tb__DOT__load_vectors__8__a5;
    vlSelfRef.tb__DOT__vector_a[6U] = __Vtask_tb__DOT__load_vectors__8__a6;
    vlSelfRef.tb__DOT__vector_a[7U] = __Vtask_tb__DOT__load_vectors__8__a7;
    vlSelfRef.tb__DOT__vector_b[0U] = __Vtask_tb__DOT__load_vectors__8__b0;
    vlSelfRef.tb__DOT__vector_b[1U] = __Vtask_tb__DOT__load_vectors__8__b1;
    vlSelfRef.tb__DOT__vector_b[2U] = __Vtask_tb__DOT__load_vectors__8__b2;
    vlSelfRef.tb__DOT__vector_b[3U] = __Vtask_tb__DOT__load_vectors__8__b3;
    vlSelfRef.tb__DOT__vector_b[4U] = __Vtask_tb__DOT__load_vectors__8__b4;
    vlSelfRef.tb__DOT__vector_b[5U] = __Vtask_tb__DOT__load_vectors__8__b5;
    vlSelfRef.tb__DOT__vector_b[6U] = __Vtask_tb__DOT__load_vectors__8__b6;
    vlSelfRef.tb__DOT__vector_b[7U] = __Vtask_tb__DOT__load_vectors__8__b7;
    VL_WRITEF_NX("Vector A: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\nVector B: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\n",0,
                 8,__Vtask_tb__DOT__load_vectors__8__a0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__a1),
                 8,__Vtask_tb__DOT__load_vectors__8__a2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__a3),
                 8,__Vtask_tb__DOT__load_vectors__8__a4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__a5),
                 8,__Vtask_tb__DOT__load_vectors__8__a6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__a7),
                 8,__Vtask_tb__DOT__load_vectors__8__b0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__b1),
                 8,__Vtask_tb__DOT__load_vectors__8__b2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__b3),
                 8,__Vtask_tb__DOT__load_vectors__8__b4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__b5),
                 8,__Vtask_tb__DOT__load_vectors__8__b6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__8__b7));
    tb__DOT__expected = 8U;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         76);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    tb__DOT__test_num = 6U;
    VL_WRITEF_NX("Test #%0d: Adding Up\n",0,32,tb__DOT__test_num);
    __Vtask_tb__DOT__load_vectors__10__b7 = 8U;
    __Vtask_tb__DOT__load_vectors__10__b6 = 7U;
    __Vtask_tb__DOT__load_vectors__10__b5 = 6U;
    __Vtask_tb__DOT__load_vectors__10__b4 = 5U;
    __Vtask_tb__DOT__load_vectors__10__b3 = 4U;
    __Vtask_tb__DOT__load_vectors__10__b2 = 3U;
    __Vtask_tb__DOT__load_vectors__10__b1 = 2U;
    __Vtask_tb__DOT__load_vectors__10__b0 = 1U;
    __Vtask_tb__DOT__load_vectors__10__a7 = 8U;
    __Vtask_tb__DOT__load_vectors__10__a6 = 7U;
    __Vtask_tb__DOT__load_vectors__10__a5 = 6U;
    __Vtask_tb__DOT__load_vectors__10__a4 = 5U;
    __Vtask_tb__DOT__load_vectors__10__a3 = 4U;
    __Vtask_tb__DOT__load_vectors__10__a2 = 3U;
    __Vtask_tb__DOT__load_vectors__10__a1 = 2U;
    __Vtask_tb__DOT__load_vectors__10__a0 = 1U;
    vlSelfRef.tb__DOT__vector_a[0U] = __Vtask_tb__DOT__load_vectors__10__a0;
    vlSelfRef.tb__DOT__vector_a[1U] = __Vtask_tb__DOT__load_vectors__10__a1;
    vlSelfRef.tb__DOT__vector_a[2U] = __Vtask_tb__DOT__load_vectors__10__a2;
    vlSelfRef.tb__DOT__vector_a[3U] = __Vtask_tb__DOT__load_vectors__10__a3;
    vlSelfRef.tb__DOT__vector_a[4U] = __Vtask_tb__DOT__load_vectors__10__a4;
    vlSelfRef.tb__DOT__vector_a[5U] = __Vtask_tb__DOT__load_vectors__10__a5;
    vlSelfRef.tb__DOT__vector_a[6U] = __Vtask_tb__DOT__load_vectors__10__a6;
    vlSelfRef.tb__DOT__vector_a[7U] = __Vtask_tb__DOT__load_vectors__10__a7;
    vlSelfRef.tb__DOT__vector_b[0U] = __Vtask_tb__DOT__load_vectors__10__b0;
    vlSelfRef.tb__DOT__vector_b[1U] = __Vtask_tb__DOT__load_vectors__10__b1;
    vlSelfRef.tb__DOT__vector_b[2U] = __Vtask_tb__DOT__load_vectors__10__b2;
    vlSelfRef.tb__DOT__vector_b[3U] = __Vtask_tb__DOT__load_vectors__10__b3;
    vlSelfRef.tb__DOT__vector_b[4U] = __Vtask_tb__DOT__load_vectors__10__b4;
    vlSelfRef.tb__DOT__vector_b[5U] = __Vtask_tb__DOT__load_vectors__10__b5;
    vlSelfRef.tb__DOT__vector_b[6U] = __Vtask_tb__DOT__load_vectors__10__b6;
    vlSelfRef.tb__DOT__vector_b[7U] = __Vtask_tb__DOT__load_vectors__10__b7;
    VL_WRITEF_NX("Vector A: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\nVector B: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\n",0,
                 8,__Vtask_tb__DOT__load_vectors__10__a0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__a1),
                 8,__Vtask_tb__DOT__load_vectors__10__a2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__a3),
                 8,__Vtask_tb__DOT__load_vectors__10__a4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__a5),
                 8,__Vtask_tb__DOT__load_vectors__10__a6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__a7),
                 8,__Vtask_tb__DOT__load_vectors__10__b0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__b1),
                 8,__Vtask_tb__DOT__load_vectors__10__b2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__b3),
                 8,__Vtask_tb__DOT__load_vectors__10__b4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__b5),
                 8,__Vtask_tb__DOT__load_vectors__10__b6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__10__b7));
    tb__DOT__expected = 0xccU;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         88);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    tb__DOT__test_num = 7U;
    VL_WRITEF_NX("Test #%0d: Decimals\n",0,32,tb__DOT__test_num);
    __Vtask_tb__DOT__load_vectors__12__b7 = 0x50U;
    __Vtask_tb__DOT__load_vectors__12__b6 = 0x46U;
    __Vtask_tb__DOT__load_vectors__12__b5 = 0x3cU;
    __Vtask_tb__DOT__load_vectors__12__b4 = 0x32U;
    __Vtask_tb__DOT__load_vectors__12__b3 = 0x28U;
    __Vtask_tb__DOT__load_vectors__12__b2 = 0x1eU;
    __Vtask_tb__DOT__load_vectors__12__b1 = 0x14U;
    __Vtask_tb__DOT__load_vectors__12__b0 = 0xaU;
    __Vtask_tb__DOT__load_vectors__12__a7 = 8U;
    __Vtask_tb__DOT__load_vectors__12__a6 = 7U;
    __Vtask_tb__DOT__load_vectors__12__a5 = 6U;
    __Vtask_tb__DOT__load_vectors__12__a4 = 5U;
    __Vtask_tb__DOT__load_vectors__12__a3 = 4U;
    __Vtask_tb__DOT__load_vectors__12__a2 = 3U;
    __Vtask_tb__DOT__load_vectors__12__a1 = 2U;
    __Vtask_tb__DOT__load_vectors__12__a0 = 1U;
    vlSelfRef.tb__DOT__vector_a[0U] = __Vtask_tb__DOT__load_vectors__12__a0;
    vlSelfRef.tb__DOT__vector_a[1U] = __Vtask_tb__DOT__load_vectors__12__a1;
    vlSelfRef.tb__DOT__vector_a[2U] = __Vtask_tb__DOT__load_vectors__12__a2;
    vlSelfRef.tb__DOT__vector_a[3U] = __Vtask_tb__DOT__load_vectors__12__a3;
    vlSelfRef.tb__DOT__vector_a[4U] = __Vtask_tb__DOT__load_vectors__12__a4;
    vlSelfRef.tb__DOT__vector_a[5U] = __Vtask_tb__DOT__load_vectors__12__a5;
    vlSelfRef.tb__DOT__vector_a[6U] = __Vtask_tb__DOT__load_vectors__12__a6;
    vlSelfRef.tb__DOT__vector_a[7U] = __Vtask_tb__DOT__load_vectors__12__a7;
    vlSelfRef.tb__DOT__vector_b[0U] = __Vtask_tb__DOT__load_vectors__12__b0;
    vlSelfRef.tb__DOT__vector_b[1U] = __Vtask_tb__DOT__load_vectors__12__b1;
    vlSelfRef.tb__DOT__vector_b[2U] = __Vtask_tb__DOT__load_vectors__12__b2;
    vlSelfRef.tb__DOT__vector_b[3U] = __Vtask_tb__DOT__load_vectors__12__b3;
    vlSelfRef.tb__DOT__vector_b[4U] = __Vtask_tb__DOT__load_vectors__12__b4;
    vlSelfRef.tb__DOT__vector_b[5U] = __Vtask_tb__DOT__load_vectors__12__b5;
    vlSelfRef.tb__DOT__vector_b[6U] = __Vtask_tb__DOT__load_vectors__12__b6;
    vlSelfRef.tb__DOT__vector_b[7U] = __Vtask_tb__DOT__load_vectors__12__b7;
    VL_WRITEF_NX("Vector A: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\nVector B: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\n",0,
                 8,__Vtask_tb__DOT__load_vectors__12__a0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__a1),
                 8,__Vtask_tb__DOT__load_vectors__12__a2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__a3),
                 8,__Vtask_tb__DOT__load_vectors__12__a4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__a5),
                 8,__Vtask_tb__DOT__load_vectors__12__a6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__a7),
                 8,__Vtask_tb__DOT__load_vectors__12__b0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__b1),
                 8,__Vtask_tb__DOT__load_vectors__12__b2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__b3),
                 8,__Vtask_tb__DOT__load_vectors__12__b4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__b5),
                 8,__Vtask_tb__DOT__load_vectors__12__b6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__12__b7));
    tb__DOT__expected = 0x7f8U;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         100);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    tb__DOT__test_num = 8U;
    VL_WRITEF_NX("Test #%0d: Identity\n",0,32,tb__DOT__test_num);
    __Vtask_tb__DOT__load_vectors__14__b7 = 0U;
    __Vtask_tb__DOT__load_vectors__14__b6 = 0U;
    __Vtask_tb__DOT__load_vectors__14__b5 = 0U;
    __Vtask_tb__DOT__load_vectors__14__b4 = 0U;
    __Vtask_tb__DOT__load_vectors__14__b3 = 0U;
    __Vtask_tb__DOT__load_vectors__14__b2 = 0U;
    __Vtask_tb__DOT__load_vectors__14__b1 = 0U;
    __Vtask_tb__DOT__load_vectors__14__b0 = 1U;
    __Vtask_tb__DOT__load_vectors__14__a7 = 0U;
    __Vtask_tb__DOT__load_vectors__14__a6 = 0U;
    __Vtask_tb__DOT__load_vectors__14__a5 = 0U;
    __Vtask_tb__DOT__load_vectors__14__a4 = 0U;
    __Vtask_tb__DOT__load_vectors__14__a3 = 0U;
    __Vtask_tb__DOT__load_vectors__14__a2 = 0U;
    __Vtask_tb__DOT__load_vectors__14__a1 = 0U;
    __Vtask_tb__DOT__load_vectors__14__a0 = 1U;
    vlSelfRef.tb__DOT__vector_a[0U] = __Vtask_tb__DOT__load_vectors__14__a0;
    vlSelfRef.tb__DOT__vector_a[1U] = __Vtask_tb__DOT__load_vectors__14__a1;
    vlSelfRef.tb__DOT__vector_a[2U] = __Vtask_tb__DOT__load_vectors__14__a2;
    vlSelfRef.tb__DOT__vector_a[3U] = __Vtask_tb__DOT__load_vectors__14__a3;
    vlSelfRef.tb__DOT__vector_a[4U] = __Vtask_tb__DOT__load_vectors__14__a4;
    vlSelfRef.tb__DOT__vector_a[5U] = __Vtask_tb__DOT__load_vectors__14__a5;
    vlSelfRef.tb__DOT__vector_a[6U] = __Vtask_tb__DOT__load_vectors__14__a6;
    vlSelfRef.tb__DOT__vector_a[7U] = __Vtask_tb__DOT__load_vectors__14__a7;
    vlSelfRef.tb__DOT__vector_b[0U] = __Vtask_tb__DOT__load_vectors__14__b0;
    vlSelfRef.tb__DOT__vector_b[1U] = __Vtask_tb__DOT__load_vectors__14__b1;
    vlSelfRef.tb__DOT__vector_b[2U] = __Vtask_tb__DOT__load_vectors__14__b2;
    vlSelfRef.tb__DOT__vector_b[3U] = __Vtask_tb__DOT__load_vectors__14__b3;
    vlSelfRef.tb__DOT__vector_b[4U] = __Vtask_tb__DOT__load_vectors__14__b4;
    vlSelfRef.tb__DOT__vector_b[5U] = __Vtask_tb__DOT__load_vectors__14__b5;
    vlSelfRef.tb__DOT__vector_b[6U] = __Vtask_tb__DOT__load_vectors__14__b6;
    vlSelfRef.tb__DOT__vector_b[7U] = __Vtask_tb__DOT__load_vectors__14__b7;
    VL_WRITEF_NX("Vector A: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\nVector B: [%0#, %0#, %0#, %0#, %0#, %0#, %0#, %0#]\n",0,
                 8,__Vtask_tb__DOT__load_vectors__14__a0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__a1),
                 8,__Vtask_tb__DOT__load_vectors__14__a2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__a3),
                 8,__Vtask_tb__DOT__load_vectors__14__a4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__a5),
                 8,__Vtask_tb__DOT__load_vectors__14__a6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__a7),
                 8,__Vtask_tb__DOT__load_vectors__14__b0,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__b1),
                 8,__Vtask_tb__DOT__load_vectors__14__b2,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__b3),
                 8,__Vtask_tb__DOT__load_vectors__14__b4,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__b5),
                 8,__Vtask_tb__DOT__load_vectors__14__b6,
                 8,(IData)(__Vtask_tb__DOT__load_vectors__14__b7));
    tb__DOT__expected = 1U;
    co_await vlSelfRef.__VtrigSched_hacbda2e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         112);
    co_await vlSelfRef.__VdlySched.delay(0x14ULL, nullptr, 
                                         "tb.sv", 151);
    VL_WRITEF_NX("Expected: %0# | Got: %0#\n",0,19,
                 tb__DOT__expected,19,vlSelfRef.tb__DOT__vector_out);
    if ((vlSelfRef.tb__DOT__vector_out == tb__DOT__expected)) {
        VL_WRITEF_NX("Test #%0d Passed!\n\n",0,32,tb__DOT__test_num);
    } else {
        VL_WRITEF_NX("Test #%0d Failed\n\n",0,32,tb__DOT__test_num);
    }
    VL_WRITEF_NX("\n   ========================= ALL TEST FINISHED =========================\n\n",0);
    VL_FINISH_MT("tb.sv", 116, "");
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb.sv", 
                                             20);
        vlSelfRef.tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb__DOT__clk)));
    }
}

void Vtb___024root___act_comb__TOP__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__temp[0U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [0U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [0U]));
    vlSelfRef.tb__DOT__dut__DOT__temp[1U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [1U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [1U]));
    vlSelfRef.tb__DOT__dut__DOT__temp[2U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [2U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [2U]));
    vlSelfRef.tb__DOT__dut__DOT__temp[3U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [3U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [3U]));
    vlSelfRef.tb__DOT__dut__DOT__temp[4U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [4U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [4U]));
    vlSelfRef.tb__DOT__dut__DOT__temp[5U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [5U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [5U]));
    vlSelfRef.tb__DOT__dut__DOT__temp[6U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [6U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [6U]));
    vlSelfRef.tb__DOT__dut__DOT__temp[7U] = (0xffffU 
                                             & (vlSelfRef.tb__DOT__vector_a
                                                [7U] 
                                                * vlSelfRef.tb__DOT__vector_b
                                                [7U]));
}

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__vector_out = vlSelfRef.tb__DOT__dut__DOT__sum;
    vlSelfRef.tb__DOT__dut__DOT__sum = ((IData)(vlSelfRef.tb__DOT__reset)
                                         ? 0U : (0x7ffffU 
                                                 & (((((((vlSelfRef.tb__DOT__dut__DOT__temp
                                                          [0U] 
                                                          + 
                                                          vlSelfRef.tb__DOT__dut__DOT__temp
                                                          [1U]) 
                                                         + 
                                                         vlSelfRef.tb__DOT__dut__DOT__temp
                                                         [2U]) 
                                                        + 
                                                        vlSelfRef.tb__DOT__dut__DOT__temp
                                                        [3U]) 
                                                       + 
                                                       vlSelfRef.tb__DOT__dut__DOT__temp
                                                       [4U]) 
                                                      + 
                                                      vlSelfRef.tb__DOT__dut__DOT__temp
                                                      [5U]) 
                                                     + 
                                                     vlSelfRef.tb__DOT__dut__DOT__temp
                                                     [6U]) 
                                                    + 
                                                    vlSelfRef.tb__DOT__dut__DOT__temp
                                                    [7U])));
}

void Vtb___024root___timing_commit(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_commit\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hacbda2e7__0.commit(
                                                   "@(posedge tb.clk)");
    }
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hacbda2e7__0.resume(
                                                   "@(posedge tb.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    Vtb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
