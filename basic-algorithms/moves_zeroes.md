## Problem: Move Zeroes (Easy)

**Link:** [LeetCode 283 - Move Zeroes](https://leetcode.com/problems/move-zeroes/)

### Approach
We use a two-pointer (read/write) in-place approach. The write pointer (`lastNonZero`) keeps track of the index where the next non-zero element should be placed, while the read pointer (`i`) iterates through the entire array. Whenever a non-zero element is encountered, it is swapped with the element at `lastNonZero`, and `lastNonZero` is incremented. This naturally pushes all `0`s toward the end of the array while preserving the relative order of non-zero elements.

### Complexity
- **Time Complexity:** $O(N)$ since we traverse the array of length $N$ in a single pass.
- **Space Complexity:** $O(1)$ auxiliary space because all swaps are done in-place without using extra array memory.

### Notes
- Swapping non-zero elements directly avoids needing a second loop to fill remaining positions with zeros.
- Works efficiently even when there are no zeros present (elements swap with themselves) or when all elements are zeros.