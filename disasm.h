#include "asm.h"

#define DEF_CMD(name, codenum, code)\
    case codenum:\
        fprintf(f, "%s\n", #name);\
        i++;\
        break;

#define DEF_REG(name, regnumber)\
    case regnumber:\
        fprintf(f, "%s\n", #name);\
        i++;\
        break;

#define DEF_CMD_REG(name, codenum, code)\
    case codenum:\
        fprintf(f, "%s\t", #name);\
        regnum = machine[++i];\
        switch(regnum)\
        {\
            DEF_REG(ax, 0)\
            DEF_REG(bx, 1)\
            DEF_REG(cx, 2)\
            DEF_REG(dx, 3)\
            DEF_REG(ex, 4)\
            DEF_REG(fx, 5)\
            DEF_REG(cat, 6)\
            DEF_REG(mur, 7)\
            DEF_REG(meow, 8)\
            DEF_REG(kitten, 9)\
        }\
        break;

#define DEF_CMD_LABEL(comname, codenum, code)\
    case codenum:\
        fprintf(f, "%s\t", #comname);\
        lblnum = machine[++i];\
        for (int j = 0; j < Labelnum; j++)\
        {\
            if (lblnum == Label[j].num)\
            {\
                fprintf(f, "%s\n", Label[j].name);\
                break;\
            }\
        }\
        i++;\
        break;

#define DEF_CMD_PUSH(name, codenum, script)\
    case codenum:\
        fprintf(f, "%s\t", #name);\
        num = machine[++i];\
        fprintf(f, "%d\n", num);\
        i++;\
        break;

#define DEF_CMD_VIDEO(name, codenum, cmdlen, script)\
    case codenum:\
        fprintf(f, "%s\n", #name);\
        i++;\
        break;


int disassemble(int machine[], int size, FILE* f)
{
    int cmd = 0;
    int num = 0;
    int i = 0;
    int regnum = 0;
    int lblnum = 0;
    while (i < size)
    {
        for (int m = 0; m < Labelnum; m++)
            if (i == Label[m].num)
            {
                fprintf(f, "%s:\n", Label[m].name);
                i++;
                break;
            }
        cmd = machine[i];
        switch (cmd)
        {
            #include "Commands.h"

            default:
                return -1;
        }
    }
    return 1;
}

#undef DEF_CMD_VIDEO
#undef DEF_CMD_PUSH
#undef DEF_CMD_LABEL
#undef DEF_CMD_REG
#undef DEF_REG
#undef DEF_CMD