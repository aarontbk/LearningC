#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

static LOG_OUTPUT_POLICY currentPolicy = LOG_OUTPUT_POLICY_NONE;
static FILE *logFile = NULL;

void logger_init(LOG_OUTPUT_POLICY policy, const char *logFilePath)
{
    currentPolicy = policy;
    if (policy & LOG_OUTPUT_POLICY_FILE)
    {
        logFile = fopen(logFilePath, "a");
    }
}

void logger_log(const char *format, ...)
{
    va_list args;           // Declare va_list
    va_start(args, format); // Initialize va_list

    if (currentPolicy == LOG_OUTPUT_POLICY_NONE)
    {
        va_end(args); // Clean up va_list
        return;
    }

    if (currentPolicy & LOG_OUTPUT_POLICY_STDOUT)
    {
        vprintf(format, args);
        printf("\n");
    }

    if (currentPolicy & LOG_OUTPUT_POLICY_FILE)
    {
        if (logFile != NULL)
        {
            vfprintf(logFile, format, args);
            fprintf(logFile, "\n");
            fflush(logFile);
        }
    }

    va_end(args); // Clean up va_list
}

void logger_destroy()
{
    if (logFile != NULL)
    {
        fclose(logFile);
    }
}
