#include <stdio.h>
#include <math.h>




int main() {

    char opp[6];
    printf("Operation (add, sub, mul, div, mod): \n");
    scanf("%s", opp);
    if (opp != ("add" | "sub" | "mul" | "div" | "mod") {
        printf("%s" "Unregonized opperation");
        return 0; 
       } 

    printf("%s", opp);

    return 0;
}



