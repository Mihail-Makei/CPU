# Stack machine
Stack machine emulator supporting the operations with .
# Structure
The stack machine has the following memory units:
 - Stack;
 - 10 Registers;
 - Graphic memory unit.
 # Supported commands
 |Command|Arguments number|Description|
 --------|----------------|-----------|
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
 |JUMP|label name|Jumps into the label.|
 # Remarks
 * The numbers from the stack are removed after the calculation.
