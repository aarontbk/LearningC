#pragma once
#include <stdio.h>
#include "logger.h"

// CR: where possible we prefer consts over macros in general. For example here, I think just MAX_USER_INPUT_SIZE needs to be macro, everything else can be strongly const types (e.g. const char* DEFAULT_LOG_FILE_PATH = "log.txt" etc)
#define DEFAULT_LOG_OUTPUT_POLICY (LOG_OUTPUT_POLICY_NONE)
#define DEFAULT_LOG_FILE_PATH "log.txt"
#define DEFAULT_LOG_LEVEL LOG_POLICY_LEVEL_NONE
#define MAX_USER_INPUT_SIZE 4096