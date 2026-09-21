#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// Local Testing Block
int main() {
    // Test Case 1: Typical Case
    char str1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    reverseString(str1, 5);
    printf("Test 1 (Typical): Expected [o, l, l, e, h] -> Output: %s\n", str1);

    // Test Case 2: Edge Case (Odd length string)
    char str2[] = {'H', 'a', 'n', 'n', 'a', 'h', '\0'};
    reverseString(str2, 6);
    printf("Test 2 (Edge):    Expected [h, a, n, n, a, H] -> Output: %s\n", str2);

    return 0;
}