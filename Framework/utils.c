#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"
#define MAX_INPUT_SIZE 128

char* time_stamp() {
    const char* dateStr = __DATE__;
    char month[4], day[3], year[5];

    // Parse the date string
    if (sscanf(dateStr, "%s %s %s", month, day, year) != 3) {
        printf("Error parsing date: %s\n", dateStr);
        return NULL;
    }

    const char* monthNames[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    int monthNum = 0;

    // Find the numeric value of the month
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, monthNames[i]) == 0) {
            monthNum = i + 1;
            break;
        }
    }

    // Create a character array to store the formatted date
    char* formattedDate = (char*)malloc(20);
    if (formattedDate != NULL) {
        snprintf(formattedDate, 20, "%02d/%s/%s", monthNum, day, year);
    }
    else {
        printf("Error allocating memory for formatted date.\n");
    }

    return formattedDate;
}

LOG_LEVEL get_logger_level()
{
    char input[MAX_INPUT_SIZE];
    LOG_LEVEL log_level = DEFAULT_LOG_LEVEL;

    while (1) {
        printf("LOG_LEVEL_NONE or LOG_LEVEL_ERROR or LOG_LEVEL_INFO\n");
        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input);
        if (input_size > 0 && input[input_size - 1] == '\n') {
            input[input_size - 1] = '\0';
        }
        if (strcmp(input, "LOG_LEVEL_NONE") == 0) {
            log_level = LOG_LEVEL_NONE;
            break;
        }
        else if (strcmp(input, "LOG_LEVEL_ERROR") == 0) {
            log_level = LOG_LEVEL_ERROR;
            break;
        }
        else if (strcmp(input, "LOG_LEVEL_INFO") == 0) {
            log_level = LOG_LEVEL_INFO;
            break;
        }
        else {
            printf("Unknown command.\n");
        }
    }
    return log_level;
}

void setup_logger_config()
{
    char input[MAX_INPUT_SIZE];
    LOG_OUTPUT_POLICY log_policy = DEFAULT_LOG_OUTPUT_POLICY;
    LOG_LEVEL log_level = DEFAULT_LOG_LEVEL;

    while (1) {
        printf("1. LOG_OUTPUT_POLICY_NONE or LOG_OUTPUT_POLICY_STDOUT or LOG_OUTPUT_POLICY_FILE.\n2. quit\n");
        fgets(input, sizeof(input), stdin);
        size_t input_size = strlen(input);
        if (input_size > 0 && input[input_size - 1] == '\n') {
            input[input_size - 1] = '\0';
        }

        if (strcmp(input, "quit") == 0) {
            printf("Exiting the program\n");
            exit(0);
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_NONE") == 0) {
            // do nothing
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT") == 0) {
            log_level = get_logger_level();
            logger__init(LOG_OUTPUT_POLICY_STDOUT, log_level);
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_FILE") == 0) {
            log_level = get_logger_level();
            logger__init(LOG_OUTPUT_POLICY_FILE, log_level);
            break;
        }
        else if (strcmp(input, "LOG_OUTPUT_POLICY_STDOUT | LOG_OUTPUT_POLICY_FILE") == 0 || strcmp(input, "LOG_OUTPUT_POLICY_FILE | LOG_OUTPUT_POLICY_STDOUT") == 0) {
            log_level = get_logger_level();
            logger__init(LOG_OUTPUT_POLICY_FILE | LOG_OUTPUT_POLICY_STDOUT, log_level);
            break;
        }
        else {
            printf("Unknown command.\n");
        }
    }
}