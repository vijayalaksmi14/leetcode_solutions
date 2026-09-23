#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

char* timeConversion(char* s) {
    // Allocate memory for 8 characters ("hh:mm:ss") + null terminator '\0'
    char* result = (char*)malloc(9 * sizeof(char));

    int hh, mm, ss;
    char am_pm[3];

    // Parse the input string (e.g., "07:05:45PM")
    sscanf(s, "%2d:%2d:%2d%2s", &hh, &mm, &ss, am_pm);

    // Convert hour based on AM/PM rules
    if (strcmp(am_pm, "PM") == 0) {
        if (hh != 12) {
            hh += 12; // PM hours except 12 PM get converted by adding 12
        }
    } else { // AM case
        if (hh == 12) {
            hh = 0; // 12 AM becomes 00
        }
    }

    // Format output string into military time ("hh:mm:ss")
    sprintf(result, "%02d:%02d:%02d", hh, mm, ss);

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
