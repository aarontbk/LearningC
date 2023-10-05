#pragma once

#define LOG(level, format, ...) logger__log(level, "%s %s [%s] %s: line %d: "format, __DATE__, __TIME__, __func__, __FILE__, __LINE__, ##__VA_ARGS__)

typedef enum
{
    LOG_OUTPUT_POLICY_NONE = 0,
    LOG_OUTPUT_POLICY_FILE = 1,
    LOG_OUTPUT_POLICY_STDOUT = 2
} LOG_OUTPUT_POLICY;

typedef enum
{
    LOG_POLICY_LEVEL_NONE,
    LOG_POLICY_LEVEL_ERROR,
    LOG_POLICY_LEVEL_INFO
}LOG_POLICY_LEVEL;

typedef struct LoggerContext {
    LOG_OUTPUT_POLICY policy;
    FILE* file_handle;
    LOG_POLICY_LEVEL level;
} LoggerContext;

struct LoggerContext;


void logger__init(LOG_OUTPUT_POLICY policy, LOG_POLICY_LEVEL level);
void logger__log(LOG_POLICY_LEVEL level, const char *format, ...);
void logger__destroy();
