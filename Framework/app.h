#pragma once
#include "logger.h"
#include <stdbool.h>

void handle_command_quit();
bool handle_command_set_logger_config(int output_policy, int log_level);
bool setup_logger_config();