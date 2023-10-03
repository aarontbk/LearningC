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
        printf("Error parsing date.\n");
        return NULL;
    }

    // Convert the month abbreviation to a numeric value
    int monthNum;
    if (strcmp(month, "Jan") == 0) {
        monthNum = 1;
    }
    else if (strcmp(month, "Feb") == 0) {
        monthNum = 2;
    }
    else if (strcmp(month, "Mar") == 0) {
        monthNum = 3;
    }
    else if (strcmp(month, "Apr") == 0) {
        monthNum = 4;
    }
    else if (strcmp(month, "May") == 0) {
        monthNum = 5;
    }
    else if (strcmp(month, "Jun") == 0) {
        monthNum = 6;
    }
    else if (strcmp(month, "Jul") == 0) {
        monthNum = 7;
    }
    else if (strcmp(month, "Aug") == 0) {
        monthNum = 8;
    }
    else if (strcmp(month, "Sep") == 0) {
        monthNum = 9;
    }
    else if (strcmp(month, "Oct") == 0) {
        monthNum = 10;
    }
    else if (strcmp(month, "Nov") == 0) {
        monthNum = 11;
    }
    else{
        monthNum = 12;
    }

    // Create a character array to store the formatted date
    char* formattedDate = (char*)malloc(20); // Allocate enough memory
    snprintf(formattedDate, 20, "%02d/%s/%s", monthNum, day, year);

    return formattedDate;
    }