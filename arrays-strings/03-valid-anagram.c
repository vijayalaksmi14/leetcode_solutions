#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

// Local Testing Block
int main() {
    // Test Case 1: Typical Case (Anagrams)
    char s1[] = "anagram";
    char t1[] = "nagaram";
    printf("Test 1 (Typical): Expected 1 -> Output: %d\n", isAnagram(s1, t1));

    // Test Case 2: Edge Case (Different Lengths / Not Anagrams)
    char s2[] = "rat";
    char t2[] = "car";
    printf("Test 2 (Edge):    Expected 0 -> Output: %d\n", isAnagram(s2, t2));

    return 0;
}