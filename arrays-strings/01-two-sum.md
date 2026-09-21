## Problem: Two Sum (Easy)
**Link:** https://leetcode.com/problems/two-sum/

### Approach
Used a nested loop (brute-force approach) to check every pair of elements in the array to see if their sum equals the target value. When a matching pair is found, their indices are returned.

### Complexity
- Time: $O(n^2)$
- Space: $O(1)$

### Notes
- Ensure dynamic memory allocation (`malloc`) is handled properly for the returned array.
- For an optimized $O(n)$ time complexity, a Hash Table can be used.