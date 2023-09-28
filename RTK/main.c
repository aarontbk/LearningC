#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "logger.h"
#include "constants.h"

int main() {
    logger__init(DEFAULT_LOG_OUTPUT_POLICY, LOG_FILE_PATH);
    LOG("Initialized log successfully, and started app");

    char command[100];
    while (1) {
        printf("Enter a command (quit/log): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break; // Exit the program
        }
        else if (strcmp(command, "log") == 0) {
            char logMessage[100];
            printf("Enter log message: ");
            scanf("%s", logMessage);
            LOG("%s", logMessage);
        }
        else {
            printf("Unknown command. Please enter 'quit' or 'log'.\n");
        }
    }

    logger__destroy();

    return 0;
}
