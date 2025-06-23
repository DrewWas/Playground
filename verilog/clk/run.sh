rm -rf obj_dir
verilator --cc --exe --build --timing utils.sv async_fifo.sv tb.sv tb_main.cpp --top-module tb -CFLAGS "-std=c++17"
./obj_dir/Vtb


