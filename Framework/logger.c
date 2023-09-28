#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

typedef struct Logger {
    LOG_OUTPUT_POLICY policy;
    FILE* file;
} Logger;

struct Logger logger;

void logger__init(LOG_OUTPUT_POLICY policy, const char *logFilePath)
{
    logger.policy = policy;
    logger.file = NULL;
    if (policy & LOG_OUTPUT_POLICY_FILE)
    {
        logger.file = fopen(logFilePath, "a");
    }
}

void logger__log(const char *format, ...)
{
    va_list args;           // Declare va_list
    va_start(args, format); // Initialize va_list

    if (logger.policy == LOG_OUTPUT_POLICY_NONE)
    {
        va_end(args); // Clean up va_list
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

    va_end(args); // Clean up va_list
}

void logger__destroy()
{
    if (logger.file != NULL)
    {
        fclose(logger.file);
    }
}
