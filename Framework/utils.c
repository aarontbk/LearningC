#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "constants.h"

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