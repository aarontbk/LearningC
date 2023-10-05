#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "constants.h"
#include "logger.h"

// CR: you have a bug that if the initial logger__init does not have LOG_OUTPUT_POLICY_FILE you do not have a valid file handle, which means even after calling update, it will fail to write to log

static LoggerContext logger = { DEFAULT_LOG_OUTPUT_POLICY, NULL, DEFAULT_LOG_LEVEL };

bool logger__init(LOG_OUTPUT_POLICY policy, LOG_POLICY_LEVEL level)
{
    logger__update_config(policy, level);

    if (policy & LOG_OUTPUT_POLICY_FILE)
    {
        logger.file_handle = fopen(DEFAULT_LOG_FILE_PATH, "a");
        if (logger.file_handle == NULL)
        {
            printf("Error opening file.");
            return false;
        }
    }
    return true;
}

bool logger__log(LOG_POLICY_LEVEL level, const char* format, ...)
{
    if (logger.policy == LOG_OUTPUT_POLICY_NONE || logger.level < level)
    {
        return true; // No logging needed
    }

    va_list args;
    va_start(args, format);

    if (logger.policy & LOG_OUTPUT_POLICY_STDOUT)
    {
        vprintf(format, args);
        printf("\n");
    }

    if (logger.policy & LOG_OUTPUT_POLICY_FILE)
    {
        if (logger.file_handle != NULL)
        {
            vfprintf(logger.file_handle, format, args);
            fprintf(logger.file_handle, "\n");
            fflush(logger.file_handle);
        }
        else
        {
            printf("Error writing to file");
            // CR: bug: you are not calling va_end in this flow and other that returns before ending
            return false;
        }
    }

    va_end(args);
    return true;
}

// CR: this is invalid code, missing parameter types... I don't even understand how it compiles
bool logger__update_config(output_policy, level)
{
    logger.policy = output_policy;
    logger.level = level;
    // CR: no need for return value if function always succeed
    return true;
}

// CR: you never call this
bool logger__destroy()
{
    if (logger.file_handle != NULL)
    {
        fclose(logger.file_handle);
    }
    if (logger.file_handle != NULL)
    {
        printf("Error closing file");
        return false;
    }
    return true;
}
