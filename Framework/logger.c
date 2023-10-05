#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "constants.h"
#include "logger.h"

static LoggerContext logger = { DEFAULT_LOG_OUTPUT_POLICY, NULL, DEFAULT_LOG_LEVEL };

void logger__init(LOG_OUTPUT_POLICY policy, LOG_POLICY_LEVEL level)
{
    logger.policy = policy;
    logger.file_handle = NULL;
    logger.level = level;

    if (policy & LOG_OUTPUT_POLICY_FILE)
    {
        logger.file_handle = fopen(DEFAULT_LOG_FILE_PATH, "a");
        if (logger.file_handle == NULL)
        {
            printf("Error opening file.");
            assert(0);
        }
    }
}

void logger__log(LOG_POLICY_LEVEL level, const char* format, ...)
{
    if (logger.policy == LOG_OUTPUT_POLICY_NONE || logger.level < level)
    {
        return; // No logging needed
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
            fclose(logger.file_handle);
        }
        else
        {
            printf("Error writing to file");
            assert(0);
        }
    }

    va_end(args);
}

void logger__destroy()
{
    if (logger.file_handle != NULL)
    {
        fclose(logger.file_handle);
    }
}
