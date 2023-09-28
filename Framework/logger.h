#pragma once
#define LOG(format, ...) logger__log("%s %s [%s] " format, __DATE__, __TIME__, __func__, ##__VA_ARGS__)

typedef enum
{
    LOG_OUTPUT_POLICY_NONE = 0,
    LOG_OUTPUT_POLICY_FILE = 1,
    LOG_OUTPUT_POLICY_STDOUT = 2
} LOG_OUTPUT_POLICY;

typedef struct Logger;


void logger__init(LOG_OUTPUT_POLICY policy, const char *logFilePath);
void logger__log(const char *format, ...);
void logger__destroy();
