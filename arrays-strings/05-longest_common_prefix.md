## Problem: Longest Common Prefix (Easy)
**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach
Used a vertical scanning technique comparing characters at index `i` across all strings, using the first string as a baseline reference. As soon as a character mismatch occurs or the end of any string is reached, the baseline string is truncated at index `i` and returned.

### Complexity
- Time: $O(S)$ where $S$ is the sum of all characters in all strings. In the worst case, all strings are identical and every character is checked.
- Space: $O(1)$ auxiliary space as the array string memory is modified in place.

### Notes
Vertical scanning allows early termination as soon as a mismatch is detected at any column, avoiding unnecessary comparisons in long strings with short common prefixes.