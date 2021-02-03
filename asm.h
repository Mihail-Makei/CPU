#ifndef CPU_V_17_ASM_H
#define CPU_V_17_ASM_H
#include "MyStack.h"
#include "Codes.h"
#include "Config.h"
#include <string.h>


#define DEF_CMD(name, commandnum, script)\
            if (strcmp(str, #name) == 0)\
                {\
                    com[size-1] = CMD_##name;\
                    num = 0;\
                }

#define DEF_CMD_REG(name, commandnum, script)\
            if (strcmp(str, #name) == 0)\
                {\
                    com[size-1] = CMD_##name;\
                    num = 0;\
                }

#define DEF_CMD_LABEL(name, commandnum, script)\
            if (strcmp(str, #name) == 0)\
                {\
                    com[size-1] = CMD_##name;\
                    num = 0;\
                }

#define DEF_CMD_PUSH(name, commandnum, script)\
            if (strcmp(str, #name) == 0)\
                {\
                    com[size-1] = CMD_##name;\
                    num = 0;\
                }

#define DEF_REG(name, regnum)\
    if (strcmp(str, #name) == 0)\
    {\
        com[size-1] = regnum;\
        num = 0;\
    }

#define DEF_CMD_VIDEO(name, codenum, cmdlen, code)\
            if (strcmp(str, #name) == 0)\
            {\
                com[size-1] = CMD_##name;\
                num = 0;\
            }

struct Labeldata
{
    int num;
    char name[MAX_LENGTH_LABEL];
};

Labeldata Label[MAX_NUM_LABEL] = {{}};          // Structure with labels

int Labelnum = 0;                               // Number of labels

int assemble(FILE* fin, int com[])
{
    if (!fin)
        printf("Input file does not exist");

    int size = 0;
    int num = 1;
    char str[MAX_LENGTH_COM] = "";
    Labelnum = 0;

    while (fscanf(fin, "%s", str) != EOF)       // First time scanning
    {
        size++;
        int length = strlen(str);
        if (str[length-1] == ':')
        {
            str[length-1] = 0;
            strcpy(Label[Labelnum].name, str);
            Label[Labelnum].num = size - 1;
            Labelnum++;
        }
    }
    size = 0;
    fseek(fin, 0, SEEK_SET);

    while (fscanf(fin, "%s", str) != EOF)       // Compilation
    {
        num = 1;
        size++;

        #include "Commands.h"

        #include "Registers.h"
        for (int i = 0; i < Labelnum; i++)
            if (strcmp(str, Label[i].name) == 0)
            {
                com[size-1] = Label[i].num;
                num = 0;
            }

        if (num)
        {
            com[size-1] = atoi(str);
            num = 0;
        }
    }

    return size;
}

#undef SUM
#undef DEF_CMD
#undef DEF_CMD_REG
#undef DEF_CMD_LABEL
#undef DEF_CMD_PUSH
#undef DEF_CMD_VIDEO
#undef DEF_REG
#endif //CPU_V_17_ASM_H
