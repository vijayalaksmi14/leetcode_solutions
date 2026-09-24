## Problem: Binary Search (Easy)

**Link:** [LeetCode 704 - Binary Search](https://leetcode.com/problems/binary-search/)

### Approach
We use the two-pointer technique (`left` and `right`) to perform a search over a sorted array. At each iteration, we calculate the midpoint `mid = left + (right - left) / 2` to avoid integer overflow and compare `nums[mid]` with the target. Depending on whether the target is smaller or larger than `nums[mid]`, we discard the right or left half of the search space respectively, cutting the problem size in half at every step.

### Complexity
- **Time Complexity:** $O(\log N)$ because the search space is halved in each step.
- **Space Complexity:** $O(1)$ auxiliary space as we only use a few pointer variables.

### Notes
- Using `left + (right - left) / 2` instead of `(left + right) / 2` is critical to prevent integer overflow when dealing with large boundary values.
- Edge cases to consider include a single-element array, an empty array, or targets smaller/larger than any element in the array.