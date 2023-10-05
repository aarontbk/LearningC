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

// CR: I don't understand this function name, it's wrong. Should be app__main_loop I think
bool setup_logger_config()
{
    char input[MAX_USER_INPUT_SIZE];
    // CR: you should do something else. Before calling the mainloop (this function), call a logger__inititialize default which will setup logger with the default values. Then, only if you get set-logger-config command re-update the settings.
    // CR: define variables only when you need them. Here you don't need them until the inner if
    int output_policy = DEFAULT_LOG_OUTPUT_POLICY;
    int log_level = DEFAULT_LOG_LEVEL;

    while (true) {
        // CR: Use the log method to print the usage, you should not have printf anywhere in the code except for the logger implementation
        printf("1. set-logger-config [LOG_OUTPUT_POLICY] [LOG_POLICY_LEVEL].\n2. quit\n");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading user input");
            return false;
        }
        input[strlen(input) - 1] = '\0';

        // CR: you should not have magic numbers like 4. In this case, you want to define a constant string for "quit" (and all other commands) and then do strncmp(input, APP_COMMAND_QUIT, strlen(APP_COMMAND_QUIT).
        if (strncmp(input, "quit", 4) == 0) {
            handle_command_quit();
            // CR: you want to do continue here. Not fall through
        }
        
        if (sscanf(input, "set-logger-config %d %d", &output_policy, &log_level) == 2)
        {
            handle_command_set_logger_config(output_policy, log_level);
            // CR: I'm confused by the meaning of the return true here... You don't return anywhere else in this function. The interface is not clear, you should have a bool app__main_loop() function that returns only on quit or fatal error.
            return true;
        }
        else {
            // CR: print the unknown command
            // CR: don't use printf
            printf("Unknown command.\n");
        }
    }
}