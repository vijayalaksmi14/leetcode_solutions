#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        // Match closing brackets
        else {
            if (top == -1) return false; // Unmatched closing bracket
            
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // Stack must be completely empty for a valid string
    return top == -1;
}

int main() {
    // Test Case 1: Standard Case (Valid Nested Brackets)
    char test1[] = "()[]{}";
    printf("Test 1 (\"%s\"): %s (Expected: true)\n", test1, isValid(test1) ? "true" : "false");

    // Test Case 2: Edge Case (Mismatched / Unbalanced Bracket)
    char test2[] = "(]";
    printf("Test 2 (\"%s\"): %s (Expected: false)\n", test2, isValid(test2) ? "true" : "false");

    return 0;
}