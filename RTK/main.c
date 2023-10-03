#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"


int main() {
    while (1) {
        char input[MAX_INPUT];

        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input);
        if (input_size > 0 && input[input_size - 1] == '\n') {
            input[input_size - 1] = '\0';
        }

        if (strcmp(input, "quit") == 0) {
            printf("Exiting the program\n");
            exit(0); // Exit the loop and the program
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_NONE") == 0) {
            logger__init(LOG_OUTPUT_POLICY_NONE);
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT") == 0) {
            logger__init(LOG_OUTPUT_POLICY_STDOUT);
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_FILE") == 0) {
            logger__init(LOG_OUTPUT_POLICY_FILE);
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT | LOG_OUTPUT_POLICY_FILE") == 0 || strcmp(input, "LOG_OUTPUT_POLICY_FILE | LOG_OUTPUT_POLICY_STDOUT") == 0) {
            logger__init(LOG_OUTPUT_POLICY_FILE | LOG_OUTPUT_POLICY_STDOUT);
            break;
        }
        else {
            printf("Unknown command.\n");
        }

    }
    LOG("Logger successfully initialized!");

    logger__destroy();

    return 0;
}
