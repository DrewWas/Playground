// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vand.h for the primary calling header

#include "Vand__pch.h"
#include "Vand__Syms.h"
#include "Vand___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vand___024root___dump_triggers__stl(Vand___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vand___024root___eval_triggers__stl(Vand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand___024root___eval_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vand___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
