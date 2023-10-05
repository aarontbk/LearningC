#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"
#include <assert.h>
#include <stdbool.h>

LOG_POLICY_LEVEL get_logger_level()
{
    char input[MAX_USER_INPUT_SIZE];
    LOG_POLICY_LEVEL log_level = DEFAULT_LOG_LEVEL;

    while (1) {
        printf("LOG_POLICY_LEVEL_NONE or LOG_POLICY_LEVEL_ERROR or LOG_POLICY_LEVEL_INFO\n");
        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input);
        if (input_size > 0 && input[input_size - 1] == '\n') {
            input[input_size - 1] = '\0';
        }
        if (strcmp(input, "LOG_POLICY_LEVEL_NONE") == 0) {
            log_level = LOG_POLICY_LEVEL_NONE;
            break;
        }
        else if (strcmp(input, "LOG_POLICY_LEVEL_ERROR") == 0) {
            log_level = LOG_POLICY_LEVEL_ERROR;
            break;
        }
        else if (strcmp(input, "LOG_POLICY_LEVEL_INFO") == 0) {
            log_level = LOG_POLICY_LEVEL_INFO;
            break;
        }
        else {
            assert(0);
        }
    }
    return log_level;
}

void setup_logger_config()
{
    char input[MAX_USER_INPUT_SIZE];
    LOG_OUTPUT_POLICY log_policy = DEFAULT_LOG_OUTPUT_POLICY;
    LOG_POLICY_LEVEL log_level = DEFAULT_LOG_LEVEL;

    while (true) {
        printf("1. LOG_OUTPUT_POLICY_NONE or LOG_OUTPUT_POLICY_STDOUT or LOG_OUTPUT_POLICY_FILE.\n2. quit\n");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading user input");
            assert(0);
        }
        size_t input_size = strlen(input);
        if (input_size > 0 && input[input_size - 1] == '\n') {
            input[input_size - 1] = '\0';
        }

        if (strcmp(input, "quit") == 0) {
            printf("Exiting the program\n");
            exit(0);
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_NONE") == 0) {
            // do nothing
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT") == 0) {
            log_level = get_logger_level();
            logger__init(LOG_OUTPUT_POLICY_STDOUT, log_level);
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_FILE") == 0) {
            log_level = get_logger_level();
            logger__init(LOG_OUTPUT_POLICY_FILE, log_level);
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT | LOG_OUTPUT_POLICY_FILE") == 0 || strcmp(input, "LOG_OUTPUT_POLICY_FILE | LOG_OUTPUT_POLICY_STDOUT") == 0) {
            log_level = get_logger_level();
            logger__init(LOG_OUTPUT_POLICY_FILE | LOG_OUTPUT_POLICY_STDOUT, log_level);
            break;
        }
        else {
            printf("Unknown command.\n");
        }
    }
}