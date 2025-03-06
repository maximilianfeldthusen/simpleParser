
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define DELIM " \t\r
"

// Function prototypes
void parseInput(char *input);
void executeCommand(char **args);

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

