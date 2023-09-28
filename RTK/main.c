#include <stdio.h>
#include <string.h>
#include "logger.h"
#include "constants.h"


int main()
{
    char comm[100];
    scanf_s("%s", comm, 4);
    logger_init(DEFAULT_LOG_OUTPUT_POLICY, LOG_FILE_PATH);

    LOG("Initialized log successfully, and started app");

    return 0;
}
