#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include "constants.h"


typedef struct Logger {
    LOG_OUTPUT_POLICY policy;
    FILE* file;
} Logger;

Logger logger = { DEFAULT_LOG_OUTPUT_POLICY, NULL };

void logger__init(LOG_OUTPUT_POLICY policy)
{
    logger.policy = policy;
    logger.file = NULL;

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

void logger__log(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    if (logger.policy == LOG_OUTPUT_POLICY_NONE)
    {
        va_end(args);
        return;
    }

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
