verilator --cc --exe --build --timing dot_product.sv tb.sv tb_main.cpp --top-module tb
./obj_dir/Vtb