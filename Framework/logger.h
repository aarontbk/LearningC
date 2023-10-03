#pragma once
#include "utils.h"

#define LOG(format, ...) logger__log("%s %s [%s] %s: line %d: "format, time_stamp(), __TIME__, __func__, __FILE__, __LINE__, ##__VA_ARGS__)

typedef enum
{
    LOG_OUTPUT_POLICY_NONE = 0,
    LOG_OUTPUT_POLICY_FILE = 1,
    LOG_OUTPUT_POLICY_STDOUT = 2
} LOG_OUTPUT_POLICY;

typedef struct Logger;


void logger__init(LOG_OUTPUT_POLICY policy);
void logger__log(const char *format, ...);
void logger__destroy();
