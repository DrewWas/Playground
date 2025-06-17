
// 32-bit instruction is in the form

// instruction[31:28] --> op_code 
// instruction[27:23] --> regfile1_read
// instruction[22:18] --> regfile2_read
// instruction[17:13] --> regfile_write_addr
// instruction[12]    --> regfile_write_en
// instruction[11]    --> branch_taken
//instruction[10:0]   --> currently unused 


module decoder #(
    parameter INSTRUCTION_LENGTH = 32,
    parameter OP_CODE_LEN = 4,
    parameter REG_FILES_LEN = 5   // Only 32 CPU regs (not imem or datamem)

) (

    input logic [INSTRUCTION_LENGTH - 1:0] instruction,
    output logic [OP_CODE_LEN - 1:0] op_code,
    output logic [REG_FILES_LEN - 1:0] regfile1_read,
    output logic [REG_FILES_LEN - 1:0] regfile2_read,
    output logic [REG_FILES_LEN - 1:0] regfile_write_addr,
    output logic regfile_write_en,
    output logic branch_taken

);

    assign op_code              = instruction[31:28];
    assign regfile1_read        = instruction[27:23];
    assign regfile2_read        = instruction[22:18];
    assign regfile_write_addr   = instruction[17:13];
    assign regfile_write_en     = instruction[12];
    assign branch_taken         = instruction[11];




endmodule





