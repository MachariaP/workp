# 0x16. C - Simple Shell

**Write a UNIX command line interpreter.**

## TASK 1

*1. Simple shell 0.1*

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- he command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (`Ctrl+D`)

*execve will be the core part of your Shell, don’t forget to pass the environ to it…*

## TASK 2

*2. Simple shell 0.2*

- Handle command lines with arguments

## TASK 3

*3. Simple shell 0.3*

- Handle the `PATH`

## TASK 4

*4. Simple shell 0.4*

- Implement the `exit` built-in, that exits the shell
- Usage: `exit`

## TASK 5

*5. Simple shell 1.0*

- Implement the `env` built-in, that prints the current environment

## TASK 6

*6. Simple shell 0.1.1*

- Write your own `getline` function
- Use a buffer to read many chars at once and call the least possible the `read` system call
- You will need to use `static` variables
- You are not allowed to use `getline`

## TASK 7

*7. Simple shell 0.2.1*

- You are not allowed to use strtok

