// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vand__pch.h"

//============================================================
// Constructors

Vand::Vand(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vand__Syms(contextp(), _vcname__, this)}
    , input_1{vlSymsp->TOP.input_1}
    , input_2{vlSymsp->TOP.input_2}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vand::Vand(const char* _vcname__)
    : Vand(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vand::~Vand() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vand___024root___eval_debug_assertions(Vand___024root* vlSelf);
#endif  // VL_DEBUG
void Vand___024root___eval_static(Vand___024root* vlSelf);
void Vand___024root___eval_initial(Vand___024root* vlSelf);
void Vand___024root___eval_settle(Vand___024root* vlSelf);
void Vand___024root___eval(Vand___024root* vlSelf);

void Vand::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vand::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vand___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vand___024root___eval_static(&(vlSymsp->TOP));
        Vand___024root___eval_initial(&(vlSymsp->TOP));
        Vand___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vand___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vand::eventsPending() { return false; }

uint64_t Vand::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vand::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vand___024root___eval_final(Vand___024root* vlSelf);

VL_ATTR_COLD void Vand::final() {
    Vand___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vand::hierName() const { return vlSymsp->name(); }
const char* Vand::modelName() const { return "Vand"; }
unsigned Vand::threads() const { return 1; }
void Vand::prepareClone() const { contextp()->prepareClone(); }
void Vand::atClone() const {
    contextp()->threadPoolpOnClone();
}
