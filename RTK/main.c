#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"
#include "app.h"

// CR: log.txt should not be in git repo
// CR: General note - all functions should be static or exported by header
// CR: General note - you have poor and messy error handling. You need to be consistent. Functions that never fail - return void. Functions that can fail return bool. Function that are allowed to call exit - should not exist!
int main() {
    // CR: main should call something like app__main_loop
    // CR: you are not checking return value
    setup_logger_config();
    LOG(LOG_POLICY_LEVEL_NONE, "message with log level none\n");
    LOG(LOG_POLICY_LEVEL_ERROR, "message with log level error\n");
    LOG(LOG_POLICY_LEVEL_INFO, "message with log level info\n");
    return 0;
}
