#include <stdio.h>
#include <string.h>
#include "Logger.h"

int main()
{
    logger_init(LOG_OUTPUT_POLICY_STDOUT, "C:\\dev\\c\\learning-c\\log.txt");

    LOG("test123");
    LOG("blablabla %d", 35);

    char *sss = "hello";
    LOG("This is my cool %d log with %s", 998, sss);

    return 0;
}
