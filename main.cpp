#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "MyStack.h"
#include "Codes.h"
#include "asm.h"
#include "disasm.h"
#include "CPU.h"

int main() {
    FILE* fin = fopen("GPU.txt", "r");
    if (fin == NULL)
    {
        printf("Input file is not found\n");
        return 0;
    }

    int com[MAX_ASM] = {};
    int size = assemble(fin, com);
    fclose(fin);

    FILE* fout = fopen("output.txt", "wb");
    fwrite(com, sizeof(int), size, fout);
    fclose(fout);

    FILE* freader = fopen("output.txt", "rb");
    fseek(freader, 1, SEEK_END);
    int lng = ftell(freader);
    fseek(freader, 0, SEEK_SET);
    fread(com, sizeof(int), lng, freader);
    fclose(freader);
    launch(com, size);
    launchGPU();

    // for (int i = 0; i < GPU.size; i++)
    //    printf("CODE %d\n", GPU.memory[i]);

    // for (int i = 0; i <= 255; i++)
    //    printf("CODE\t%d\tSYMBOL\t%c\n", i, i);

    FILE* fdisasm = fopen("disasm.txt", "wb");
    disassemble(com, size, fdisasm);
    fclose(fdisasm);

    return 0;
}