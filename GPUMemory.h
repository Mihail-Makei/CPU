#include "Config.h"
#include "MyStack.h"
#include "ConsoleGraphics.h"

#define DEF_CMD(name, cmdnum, code) {}

#define DEF_CMD_REG(name, cmdnum, code) {}

#define DEF_CMD_LABEL(name, cmdnum, code) {}

#define DEF_CMD_PUSH(name, cmdnum, code) {}

#define DEF_CMD_VIDEO(name, cmdnum, cmdlen, code)\
    case cmdnum:\
        code\
        break;


struct GPU                                              // GPU structure
{
    int memory[MAX_GPU];
    int size;
};

GPU GPU = {};                                           // GPU memory

int launchGPU()                                         // GPU itself
{
    stack_t stk = {};
    StackCreate(&stk);

    for (int i = 0; i < GPU.size; i++)
    {
        switch (GPU.memory[i])
        {
            #include "Commands.h"

            default:
                printf("GPU error\n");
                return 0;
        }
    }

    StackDestruct(&stk);
    return 1;
}

#undef DEF_CMD
#undef DEF_CMD_PUSH
#undef DEF_CMD_REG
#undef DEF_CMD_LABEL
#undef DEF_CMD_VIDEO