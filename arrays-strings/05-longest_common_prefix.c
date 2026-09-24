#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    // Iterate character by character using the first string as baseline
    for (int i = 0; strs[0][i] != '\0'; i++) {
        char c = strs[0][i];

        // Check character against all other strings
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                // Truncate first string at mismatch point
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}

// Local testing main block
int main() {
    // Typical test case
    char* test1[] = {"flower", "flow", "flight"};
    printf("Test 1 (\"flower\", \"flow\", \"flight\"): %s\n", 
           strcmp(longestCommonPrefix(test1, 3), "fl") == 0 ? "PASSED (\"fl\")" : "FAILED");

    // Edge test case: No common prefix
    char* test2[] = {"dog", "racecar", "car"};
    printf("Test 2 (\"dog\", \"racecar\", \"car\"): %s\n", 
           strcmp(longestCommonPrefix(test2, 3), "") == 0 ? "PASSED (\"\")" : "FAILED");

    return 0;
}