#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include "constants.h"


typedef struct Logger {
    LOG_OUTPUT_POLICY policy;
    FILE* file;
    LOG_LEVEL level;
} Logger;

Logger logger = { DEFAULT_LOG_OUTPUT_POLICY, NULL, DEFAULT_LOG_LEVEL };

void logger__init(LOG_OUTPUT_POLICY policy, LOG_LEVEL level)
{
    logger.policy = policy;
    logger.file = NULL;
    logger.level = level;

    if (policy & LOG_OUTPUT_POLICY_FILE)
    {
        logger.file = fopen(LOG_FILE_PATH, "a");
        if (logger.file == NULL)
        {
            printf("Error opening file.");
            exit(0);
        }
    }
}

void logger__log(const char* format, LOG_LEVEL level, ...)
{
    if (logger.policy == LOG_OUTPUT_POLICY_NONE || logger.level < level)
    {
        return; // No logging needed
    }

    va_list args;
    va_start(args, level);

    if (logger.policy & LOG_OUTPUT_POLICY_STDOUT)
    {
        vprintf(format, args);
        printf("\n");
    }

    if (logger.policy & LOG_OUTPUT_POLICY_FILE)
    {
        if (logger.file != NULL)
        {
            vfprintf(logger.file, format, args);
            fprintf(logger.file, "\n");
            fflush(logger.file);
        }
    }

    va_end(args);
}

void logger__destroy()
{
    if (logger.file != NULL)
    {
        fclose(logger.file);
    }
}
