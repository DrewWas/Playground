

.global _main
.align 2

_main:
    b _printf
    b _terminate


_printf:
    mov X0, #1
    adr X1, fsp 
    mov X2, #6
    mov X16, #4

    svc 0



_terminate:
    mov X0, #0
    mov X16, #1
    svc 0

fsp:
    .ascii "FSP!!\n"

