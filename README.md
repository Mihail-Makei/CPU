# Stack machine
Stack machine emulator supporting the operations with .
# Structure
The stack machine has the following memory units:
 - Stack;
 - Address stack;
 - 10 Registers;
 - Graphic memory unit.
 # Supported commands
 |Command|Arguments|Description|
 --------|---------|-----------|
 |PUSH|1 number|Pushes the argument into the stack.|
 |POP|1 number|Pops the argument from the stack.|
 |ADD*|None|Calculates the sum of two top numbers from the stack and pushes the result into the stack.|
 |SUB|None|Substitutes the top number of the stack from the underlying one and pushes result into the stack.|
 |MUL|None|Multiplies two top numbers and pushes the result into the stack.|
 |DIV|None|Divides the top number of the stack by the underlying one and pushes the result into the stack.|
 |MOD|None|Finds the modulus of the division.|
 |END|None|Finishes the work, shutting down the machine.|
 |IN|None|Pushes the number from standart input (keyboard) on top of the stack.|
 |OUTTOP|None|Prints the number from the top of the stack not removing it.|
 |OUTPOP|None|Prints the number from the top of the stack popping it.|
 |PUSHREG|1 register name|Pushes the value from the register into the stack.|
 |POPREG|1 register name|Pops the number from the top of the stack and puts it into the register.|
 |JUMP|label name|Jumps onto the label.|
 |JE|label name|Jumps onto the label if the top number of the stack is equal to the underlying one.|
 |JNE|label name|Jumps onto the label if the top number of the stack is not equal to the underlying one.|
 |JM|label name|Jumps onto the label if the top number of the stack is more than the underlying one.|
 |JL|label name|Jumps onto the label if the top number of the stack is less than the underlying one.|
 |JNM|label name|Jumps onto the label if the top number of the stack is not more than the underlying one.|
 |JNL|label name|Jumps onto the label if the top number of the stack is not less than the underlying one.|
 |SQRT|None|Calculates the square root of the top number of the stack and pushes it onto the top of the stack.|
 |CALL|label name|Pushes the address of the next command into the address stack and jumps onto the label.|
 |RET|None|Jumps onto the top address from the address stack and removes it from the address stack.|
 |WINDOWSET**|None|Sets the Window W x H, where W is width, H is height, the arguments are taken from the stack. (WH)|
 |PIXEL|None|Writes the ASCII symbol C into the pixel with coordinates (X, Y). (XYC)|
 |RECTANGLE|None|Draws the Rectangle with the edges coordinates X1, Y1, X2, Y2 and ASCII-symbol C used. (X1, Y1, X2, Y2, C)|
 |VLINE|None|Draws the vertical line with X, Y1, Y2 edges coordinates with ASCII-symbol C. (X, Y1, Y2, C)|
 |HLINE|None|Draws the horizontal line with X1, X2, Y edges coordinates with ASCII-symbol C. (X1, X2, Y, C)|
 |LINE|None|Draws the line with (X1, Y1), (X2, Y2) edges with ASCII-symbol C. (X1, Y1, X2, Y2, C)|
 |SHOW***|None|Outputs the Window onto the screen.|
 |CLEAR|None|Clears the Window.|
 |PARTCLEAR|None|Clears the rectangle with edges coordinates X1, Y1, X2, Y2. (X1, Y1, X2, Y2)|
 # Remarks
 - * The numbers from the stack are removed after the calculation in ADD, SUB, MUL, DIV, MOD, SQRT commands.
 - ** All the GPU commands (WINDOWSET, POINT, CIRCLE, etc.) take the arguments from the stack (so they appear in the reversed order). The direct order of the arguments is shown in the brackets.
 - *** The data written in the graphic memory is not output automatically - a SHOW instruction is to be used.
