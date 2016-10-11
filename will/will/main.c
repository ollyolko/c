#include <stdio.h>

int main()
{
    FILE *in;
    in=fopen("input.dat", "w");
    if(!in){
        printf("error open file");
    }
    fprintf(in,"Hello World!\n");

    fclose(in);
    return 0;
}
