#define PUSHSTK(a) StackPush(&stk, a)
#define POPSTK StackPop(&stk)
#define TOPSTK StackTop(&stk)


DEF_CMD_PUSH(PUSH, 1,
{
    PUSHSTK(machinecode[++i]);
})

DEF_CMD(POP, 2,
{
    POPSTK;
})

DEF_CMD(ADD, 3,
{
    PUSHSTK(POPSTK + POPSTK);
})

DEF_CMD(SUB, 4,
{
    PUSHSTK(POPSTK - POPSTK);
})

DEF_CMD(MUL, 5,
{
    PUSHSTK(POPSTK * POPSTK);
})

DEF_CMD(DIV, 6,
{
    PUSHSTK(POPSTK / POPSTK);
})

DEF_CMD(MOD, 7,
{
    PUSHSTK(POPSTK % POPSTK);
})

DEF_CMD(END, 8, {
    int result = TOPSTK;
    StackDestruct(&stk);
    return result;
})

DEF_CMD(IN, 9, {
    int input = 0;
    scanf("%d", &input);
    PUSHSTK(input);
})

DEF_CMD(OUTPOP, 10, {
    printf("OUTPUT %d\n", POPSTK);
})

DEF_CMD(OUTTOP, 11, {
    printf("OUTPUT %d\n", StackTop(&stk));
})

DEF_CMD_REG(PUSHREG, 12, {
    int regnum = machinecode[++i];
    reg[regnum] = POPSTK;
})

DEF_CMD_REG(POPREG, 13, {
    int regnum = machinecode[++i];
    PUSHSTK(reg[regnum]);
})

DEF_CMD_LABEL(JUMP, 14, {
    int cmdnum = machinecode[++i];
    i = cmdnum;
})

DEF_CMD_LABEL(JE, 15, {
    int temp = POPSTK;
    if (temp == TOPSTK)
    {
        int cmdnum = machinecode[++i];
        i = cmdnum;
    }
    PUSHSTK(temp);
})

DEF_CMD_LABEL(JNE, 16, {
    int temp = POPSTK;
    if (temp != TOPSTK)
    {
        int cmdnum = machinecode[++i];
        i = cmdnum;
    }
    PUSHSTK(temp);
})

DEF_CMD_LABEL(JM, 17, {
    int temp = POPSTK;
    if (temp > TOPSTK)
    {
        int cmdnum = machinecode[++i];
        i = cmdnum;
    }
    PUSHSTK(temp);
})

DEF_CMD_LABEL(JL, 18, {
    int temp = POPSTK;
    if (temp < TOPSTK)
    {
        int cmdnum = machinecode[++i];
        i = cmdnum;
    }
    PUSHSTK(temp);
})

DEF_CMD_LABEL(JNM, 19, {
    int temp = POPSTK;
    if (temp <= TOPSTK)
    {
        int cmdnum = machinecode[++i];
        i = cmdnum;
    }
    PUSHSTK(temp);
})

DEF_CMD_LABEL(JNL, 20, {
    int temp = POPSTK;
    if (temp >= TOPSTK)
    {
        int cmdnum = machinecode[++i];
        i = cmdnum;
    }
    PUSHSTK(temp);
})

DEF_CMD(SQRT, 21, {
    PUSHSTK((int)sqrt(POPSTK));
})

DEF_CMD_LABEL(CALL, 22, {
    int cmdnum = machinecode[++i];
    StackPush(&proc, i);
    i = cmdnum;
})

DEF_CMD(RET, 23, {
    i = StackPop(&proc);
})

/*DEF_CMD_VIDEO(PUSHGPU, 24, {
    GPU.memory[size] = machinecode[++i];
    size++;
})*/

DEF_CMD_VIDEO(WINDOWSET, 25, 2, {
    i += 2;
    SetWindow(GPU.memory[i-1], GPU.memory[i]);
})

DEF_CMD_VIDEO(PIXEL, 26, 3, {
    i += 3;
    Pixel(GPU.memory[i-2], GPU.memory[i-1], GPU.memory[i]);
})

DEF_CMD_VIDEO(CIRCLE, 27, 4, {
    i += 4;
    Circle(GPU.memory[i-3], GPU.memory[i-2], GPU.memory[i-1], GPU.memory[i]);
})

DEF_CMD_VIDEO(RECTANGLE, 28, 5, {
    i += 5;
    Rectangle(GPU.memory[i-4], GPU.memory[i-3], GPU.memory[i-2], GPU.memory[i-1], GPU.memory[i]);
})

DEF_CMD_VIDEO(VLINE, 29, 4, {
    i += 4;
    Vline(GPU.memory[i-3], GPU.memory[i-2], GPU.memory[i-1], GPU.memory[i]);
})

DEF_CMD_VIDEO(HLINE, 30, 4, {
    i += 4;
    Hline(GPU.memory[i-3], GPU.memory[i-2], GPU.memory[i-1], GPU.memory[i]);
})

DEF_CMD_VIDEO(LINE, 31, 5, {
    i += 5;
    Line(GPU.memory[i-4], GPU.memory[i-3], GPU.memory[i-2], GPU.memory[i-1], GPU.memory[i]);
})

DEF_CMD_VIDEO(SHOW, 32, 0, {
    Draw();
})

DEF_CMD_VIDEO(CLEAR, 33, 0, {
    WindowClear();
})

DEF_CMD_VIDEO(PARTCLEAR, 34, 4, {
    i += 4;
    PartClear(GPU.memory[i-3], GPU.memory[i-2], GPU.memory[i-1], GPU.memory[i]);
})