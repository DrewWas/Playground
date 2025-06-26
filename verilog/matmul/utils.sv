
`timescale 1ns/10ps

package testing_packages;
    function automatic void generate_mat 
    (input int n,m, ref element_t mat[][]);
        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < m; j++) begin
                mat[i][j] = element_t'($urandom_range(-100,100));
            end
        end
    endfunction

endpackage

