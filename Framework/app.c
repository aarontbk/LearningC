#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"
#include <assert.h>
#include <stdbool.h>

void handle_command_quit()
{
    printf("Exiting the program\n");
    assert(0);
}

bool handle_command_set_logger_config(int output_policy, int log_level)
{
    if (output_policy >= 0 && output_policy <= 3 && log_level >= 0 && log_level <= 2)
    {
        logger__init(output_policy, log_level);
        return true;
    }
    else
    {
        return false;
    }
}

bool setup_logger_config()
{
    char input[MAX_USER_INPUT_SIZE];
    int output_policy = DEFAULT_LOG_OUTPUT_POLICY;
    int log_level = DEFAULT_LOG_LEVEL;

    while (true) {
        printf("1. set-logger-config [LOG_OUTPUT_POLICY] [LOG_POLICY_LEVEL].\n2. quit\n");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading user input");
            return false;
        }
        input[strlen(input) - 1] = '\0';

        if (strncmp(input, "quit", 4) == 0) {
            handle_command_quit();
        }
        
        if (sscanf(input, "set-logger-config %d %d", &output_policy, &log_level) == 2)
        {
            handle_command_set_logger_config(output_policy, log_level);
            return true;
        }
        else {
            printf("Unknown command.\n");
        }
    }
}