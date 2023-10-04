#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"
#include "utils.h"

int main() {
    
    setup_logger_config();
    LOG("message with log level none\n", LOG_LEVEL_NONE);
    LOG("message with log level error\n", LOG_LEVEL_ERROR);
    LOG("message with log level info\n", LOG_LEVEL_INFO);
    return 0;
}
