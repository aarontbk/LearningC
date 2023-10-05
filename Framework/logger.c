#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "constants.h"
#include "logger.h"

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
            return false;
        }
    }

    va_end(args);
    return true;
}

bool logger__update_config(output_policy, level)
{
    logger.policy = output_policy;
    logger.level = level;
    return true;
}

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
