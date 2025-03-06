## Documentation

### simpleParser

This C code implements a simple command-line interface (CLI) that allows users to input commands and receive responses based on those commands. Here's a breakdown of the code:

### Header Files

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```
- **`<stdio.h>`**: This header file is included for standard input and output functions (like `printf` and `fgets`).
- **`<stdlib.h>`**: This is included for utility functions like `atoi`, which converts strings to integers.
- **`<string.h>`**: This header is included for string manipulation functions like `strtok`, `strncmp`, and `strcmp`.

### Constants

```c
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define DELIM " \t\r
"
```
- **`MAX_INPUT_SIZE`**: The maximum size for the input buffer.
- **`MAX_ARG_SIZE`**: The maximum number of arguments that can be parsed.
- **`DELIM`**: A string containing delimiters (space, tab, carriage return, newline) used for tokenizing the input.

### Function Prototypes

```c
void parseInput(char *input);
void executeCommand(char **args);
```
These are declarations for two functions that will be defined later in the code.

### Main Function

```c
int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the simple backend parser!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  // Error or EOF
        }

        // Check for exit command
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        // Parse and execute the input command
        parseInput(input);
    }

    return 0;
}
```

- The program starts by welcoming the user and instructing them how to exit.
- An infinite loop is initiated that waits for user input.
- **`fgets`** is used to read a line of input from the user. If there is an error or EOF, it breaks the loop.
- The program checks if the user typed "exit" to terminate the program.
- If not, it calls the `parseInput` function to handle the input.

### `parseInput` Function

```c
void parseInput(char *input) {
    char *args[MAX_ARG_SIZE];
    int argCount = 0;

    // Tokenizing the input string based on the delimiters
    char *token = strtok(input, DELIM);
    while (token != NULL && argCount < MAX_ARG_SIZE - 1) {
        args[argCount++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argCount] = NULL;  // Null-terminate the array of arguments

    // Execute the command
    executeCommand(args);
}
```

- This function takes the input string and tokenizes it into individual arguments based on the specified delimiters.
- It uses `strtok` to split the string into tokens. Each token (argument) is stored in the `args` array until the maximum number of arguments is reached.
- The last entry in the `args` array is set to `NULL` to indicate the end of the arguments.
- After parsing, it calls `executeCommand` to process the command.

### `executeCommand` Function

```c
void executeCommand(char **args) {
    if (args[0] == NULL) {
        return;  // No command entered
    }

    // Example command handling
    if (strcmp(args[0], "hello") == 0) {
        printf("Hello, World!\n");
    } else if (strcmp(args[0], "add") == 0 && args[1] != NULL && args[2] != NULL) {
        int num1 = atoi(args[1]);
        int num2 = atoi(args[2]);
        printf("Result: %d
", num1 + num2);
    } else if (strcmp(args[0], "sub") == 0 && args[1] != NULL && args[2] != NULL) {
        int num1 = atoi(args[1]);
        int num2 = atoi(args[2]);
        printf("Result: %d
", num1 - num2);
    } else {
        printf("Unknown command: %s
", args[0]);
    }
}
```

- This function checks if any command was entered. If `args[0]` is `NULL`, it simply returns.
- It compares the first argument (`args[0]`) with known commands:
  - **`hello`**: Prints "Hello, World!".
  - **`add`**: If two additional arguments are provided, it converts them to integers using `atoi`, adds them, and prints the result.
  - **`sub`**: Similar to `add`, but it subtracts the second number from the first.
- If the command doesn't match any known ones, it prints an "Unknown command" message.

### Summary
This code implements a simple command-line interface that can parse and execute basic commands like "hello", "add", and "sub". It demonstrates basic string processing, command execution, and user interaction in C. 


![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
