#pragma once

#define LOG(format, level, ...) logger__log("%s %s [%s] %s: line %d: "format, level, time_stamp(), __TIME__, __func__, __FILE__, __LINE__, ##__VA_ARGS__)

typedef enum
{
    LOG_OUTPUT_POLICY_NONE = 0,
    LOG_OUTPUT_POLICY_FILE = 1,
    LOG_OUTPUT_POLICY_STDOUT = 2
} LOG_OUTPUT_POLICY;

typedef enum
{
    LOG_LEVEL_NONE = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_INFO = 2
}LOG_LEVEL;

typedef struct Logger;


void logger__init(LOG_OUTPUT_POLICY policy, LOG_LEVEL level);
void logger__log(const char *format, LOG_LEVEL level, ...);
void logger__destroy();
