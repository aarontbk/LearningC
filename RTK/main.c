#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"

#define MAX_INPUT_SIZE 128

int main() {
    char input[MAX_INPUT_SIZE];
    int log_policy = LOG_OUTPUT_POLICY_NONE;

    while (1) {
        printf("1. LOG_OUTPUT_POLICY_NONE or LOG_OUTPUT_POLICY_STDOUT or LOG_OUTPUT_POLICY_FILE.\n2. quit\n");
        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input);
        if (input_size > 0 && input[input_size - 1] == '\n') {
            input[input_size - 1] = '\0';
        }

        if (strcmp(input, "quit") == 0) {
            printf("Exiting the program\n");
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_NONE") == 0) {
            log_policy = LOG_OUTPUT_POLICY_NONE;
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT") == 0) {
            log_policy = LOG_OUTPUT_POLICY_STDOUT;
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_FILE") == 0) {
            log_policy = LOG_OUTPUT_POLICY_FILE;
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT | LOG_OUTPUT_POLICY_FILE") == 0 || strcmp(input, "LOG_OUTPUT_POLICY_FILE | LOG_OUTPUT_POLICY_STDOUT") == 0) {
            log_policy = LOG_OUTPUT_POLICY_STDOUT | LOG_OUTPUT_POLICY_FILE;
            break;
        }
        else {
            printf("Unknown command.\n");
        }
    }

    if (log_policy != LOG_OUTPUT_POLICY_NONE) {
        logger__init(log_policy);
        LOG("Logger successfully initialized!");
        logger__destroy();
    }

    return 0;
}
