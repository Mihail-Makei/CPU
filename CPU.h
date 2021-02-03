#ifndef CPU_V_17_CPU_H
#define CPU_V_17_CPU_H

#include "Config.h"
#include "GPUMemory.h"


#define DEF_CMD(name, cmdnum, code)\
    case cmdnum:\
        code\
        break;

#define DEF_CMD_REG(name, cmdnum, code)\
    case cmdnum:\
        code\
        break;

#define DEF_CMD_LABEL(name, cmdnum, code)\
    case cmdnum:\
        code\
        break;

#define DEF_CMD_PUSH(name, cmdnum, code)\
    case cmdnum:\
        code\
        break;

#define DEF_CMD_VIDEO(name, cmdnum, cmdlen, code)\
    case cmdnum:\
        temp = GPU.size;\
        GPU.memory[temp] = cmdnum;\
        GPU.size++;\
        for (int j = 0; j < cmdlen; j++)\
        {\
            temp = GPU.size;\
            GPU.memory[temp] = StackPop(&stk);\
            GPU.size++;\
        }\
        break;


#define SUM(a, b, code)\
    case b:\
        printf("%s\n", #a);\
        code\
        break;

int launch(int machinecode[], int size)
{
    stack_t stk = {};
    stack_t proc = {};
    int reg[REG_NUM] = {};
    int temp = 0;
    StackCreate(&stk);
    StackCreate(&proc);

    for (int i = 0; i < size; i++)
    {
        switch (machinecode[i])
        {
            #include "Commands.h"
        }
    }

    printf("Syntax error. Program is not finished\n");
    StackDestruct(&stk);
    StackDestruct(&proc);
    return -1;
}

#undef DEF_CMD
#undef DEF_CMD_REG
#undef DEF_CMD_LABEL
#undef DEF_CMD_PUSH
#undef DEF_CMD_VIDEO
#undef POPSTK
#undef PUSHSTK
#endif //CPU_V_17_CPU_H
