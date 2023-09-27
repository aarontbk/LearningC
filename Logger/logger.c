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
        printf("%s ", get_time());
        vprintf(format, args);
        printf("\n");
    }

    if (currentPolicy & LOG_OUTPUT_POLICY_FILE)
    {
        if (logFile != NULL)
        {
            fprintf(logFile, "%s ", get_time());
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

char *get_time()
{
    static char time_string[50]; // Adjust the size as needed
    time_t current_time;
    struct tm *time_info;

    // Get the current time
    time(&current_time);

    // Convert the current time to a struct tm
    time_info = localtime(&current_time);

    // Convert the struct tm to a formatted time string
    strftime(time_string, sizeof(time_string), "%d-%m-%Y %H:%M:%S", time_info);

    return time_string;
}
