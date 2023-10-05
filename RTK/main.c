#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"
#include "app.h"

int main() {
    
    setup_logger_config();
    LOG(LOG_POLICY_LEVEL_NONE, "message with log level none\n");
    LOG(LOG_POLICY_LEVEL_ERROR, "message with log level error\n");
    LOG(LOG_POLICY_LEVEL_INFO, "message with log level info\n");
    return 0;
}
