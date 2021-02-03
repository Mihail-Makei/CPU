//
// Created by User on 17.10.2019.
//

#ifndef CPU_V_17_CODES_H
#define CPU_V_17_CODES_H

enum Commands
{
#define DEF_CMD_PUSH(name, num, code)\
    CMD_##name = num,
#define DEF_CMD(name, num, code) \
    CMD_##name = num,
#define DEF_CMD_REG(name, num, code) \
    CMD_##name = num,
#define DEF_CMD_LABEL(name, num, code) \
    CMD_##name = num,
#define DEF_CMD_VIDEO(name, num, cmdlen, code)\
    CMD_##name = num,
#include "Commands.h"
};

#undef DEF_CMD_PUSH
#undef DEF_CMD_REG
#undef DEF_CMD_LABEL
#undef DEF_CMD
#undef DEF_CMD_VIDEO
#endif //CPU_V_17_CODES_H
