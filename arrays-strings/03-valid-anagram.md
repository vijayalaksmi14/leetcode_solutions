## Problem: Valid Anagram (Easy)
**Link:** https://leetcode.com/problems/valid-anagram/

### Approach
Used a fixed-size frequency array of size 26 to count occurrences of each lowercase English letter. We iterate through both strings simultaneously, incrementing character frequencies for string `s` and decrementing for string `t`. If all character counts balance back to zero, the two strings are valid anagrams.

### Complexity
- Time: $O(n)$ where $n$ is the length of the strings.
- Space: $O(1)$ auxiliary space since the frequency array remains fixed at size 26 regardless of input size.

### Notes
- Checking string lengths upfront ($O(1)$ guard) allows immediate termination for unequal-length inputs.
- Local testing confirmed both typical matching cases and mismatch edge cases pass before submission.