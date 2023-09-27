#include <stdio.h>
#include <string.h>
#include "Logger.h"

int main()
{
    logger_init(LOG_OUTPUT_POLICY_STDOUT, "C:\\dev\\c\\learning-c\\log.txt");

    logger_log("test123");
    logger_log("blablabla");

    char *sss = "hello";
    LOG("This is my cool %d log with %s", 998, sss);

    return 0;
}
