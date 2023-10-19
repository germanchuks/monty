# Monty

## Description
This Monty project is an interpreter designed to process Monty ByteCode files.Monty is a simple stack-based programming language that allows users to execute a set of operations on a stack. The project involves the implementation of diverse opcodes that manipulate the stack and process data. The interpreter reads Monty ByteCode files, executing operations based on the file's content.

### Key Features:

Feature | Description
--- | ---
`push` | The `push` opcode allows pushing an integer onto the stack.
`pall` | The `pall` opcode prints all values on the stack.
`pint` | The `pint` opcode prints the value at the top of the stack.
`pop` | The `pop` opcode removes the top element from the stack.
`swap` | The `swap` opcode swaps the top two elements of the stack.
`add` | The `add` opcode adds the top two elements of the stack.
`nop` | The `nop` opcode does nothing.
`sub`, `div`, `mul`, `mod` | Opcodes for subtraction, division, multiplication, and modulus calculations.
`comments` | Support for comments, lines starting with `#` are treated as comments.
`pchar`, `pstr` | Opcodes for printing characters and strings.
`rotl`, `rotr` | Opcodes for rotating the stack to the top and bottom.
`stack`, `queue` | Opcodes to switch between stack and queue modes.
`Brainf*ck` | Includes a Brainf*ck script (.bf) to print "School."
`Add Two Digits` | Brainf*ck script that reads two digits from stdin, adds them, and prints the result.
`Multiplication` | Brainf*ck script that multiplies two digits from stdin and prints the result.

### File Usage
File Name | Description
--- | ---
[monty.c](https://github.com/germanchuks/monty/blob/master/alias_manager.c) | Contains the main function of the Monty ByteCode Interpreter.
[monty.h](https://github.com/germanchuks/monty/blob/master/cmd_util.c) | Header file Containing the various data structures, function prototypes, and global variable declarations used throughout this project.
[opcode_handlers_1.c](https://github.com/germanchuks/monty/blob/master/opcode_handlers_1.c) | Consists of functions to handle various Monty ByteCode operations including push (adding elements to the stack), pall (printing stack elements), pint (printing the top element), pop (removing the top element), and swap (swapping top stack elements), ensuring proper error handling and execution.
[opcode_handlers_2.c](https://github.com/germanchuks/monty/blob/master/opcode_handlers_2.c) | Comprises functions for handling Monty ByteCode operations, including "add" (addition of the top two stack elements), "nop" (no operation), "sub" (subtraction of top stack element from the second-top element), and "div_opc" (division of the top two stack elements).
[opcode_handlers_3.c](https://github.com/germanchuks/monty/blob/master/opcode_handlers_3.c) | Comprises the "mul" function which multiplies the second-top element by the top element of the stack, ensuring proper error handling for cases where the stack is too short for multiplication. The "mod" function calculates the remainder of the division of the second-top element by the top element of the stack and handles cases of division by zero and insufficient elements in the stack.
[opcode_rot_handlers.c](https://github.com/germanchuks/monty/blob/master/opcode_rot_handlers.c) | Contains the "rotl" function which rotates the stack by moving the top element to the front and handles cases where the stack is empty or contains only one element. The "rotr" function rotates the stack by moving the bottom element to the top and also manages cases with an empty stack or a single element stack.
[opcode_str_handlers.c](https://github.com/germanchuks/monty/blob/master/opcode_str_handlers.c) | Contains the "pchar" function prints the character at the top of the stack, followed by a newline, checking for an empty stack and values outside the ASCII range. The "pstr" function prints a string starting from the top of the stack until a null byte or a non-ASCII character is encountered.
[run_opcode.c](https://github.com/germanchuks/monty/blob/master/run_opcode.c) | Contains a function responsible for executing Monty opcode commands
[stack_queue_mode.c](https://github.com/germanchuks/monty/blob/master/stack_queue_mode.c) | Contains the stack_mode and queue_mode functions, responsible for setting the Monty program to either stack mode or queue mode.
[utility_functions.c](https://github.com/germanchuks/monty/blob/master/utility_functions.c) | Contains prepend, enqueue, and free_stack functions, responsible for managing the stack in the Monty program.
[1000-school.bf](https://github.com/germanchuks/monty/blob/master/bf/1000-school.bf) | bf script that prints `School`
[1001-add.bf](https://github.com/germanchuks/monty/blob/master/bf/1001-add.bf) | bf script which handles the addition of two digits read from stdin and prints the result
[1002-mul.bf](https://github.com/germanchuks/monty/blob/master/bf/1002-mul.bf) | bf script handling the multiplication of two digits read from stdin and prints the result
[1003-mul.bf](https://github.com/germanchuks/monty/blob/master/bf/1003-mul.bf) | bf script handling the multiplication of two digits read from stdin and prints the result

### Compilation
```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

### Usage
```
monty file
```

### Examples
```
$ ./monty bytecodes/06.m 
```

### Bugs
No known bugs.

## Authors
* **Michael Chukwunwe** (https://github.com/stuckwithprogression)
* **German Daniel** (https://github.com/germanchuks)
