// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VAND__SYMS_H_
#define VERILATED_VAND__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vand.h"

// INCLUDE MODULE CLASSES
#include "Vand___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vand__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vand* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vand___024root                 TOP;

    // CONSTRUCTORS
    Vand__Syms(VerilatedContext* contextp, const char* namep, Vand* modelp);
    ~Vand__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
