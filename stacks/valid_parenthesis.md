## Problem: Valid Parentheses (Easy)

**Link:** [LeetCode 20 - Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

### Approach
We use a Last-In, First-Out (LIFO) stack implemented via a character array. As we scan the string, opening brackets `(`, `{`, `[` are pushed onto the stack. When a closing bracket is encountered, we pop the top element and verify that it matches the corresponding opening pair. If there is a mismatch or if the stack is empty when a closing bracket arrives, the string is invalid.

### Complexity
- **Time Complexity:** $O(N)$ where $N$ is the length of the string, as we traverse it once.
- **Space Complexity:** $O(N)$ to store characters in the stack array in the worst-case scenario.

### Notes
- Ensure the stack is empty (`top == -1`) at the end to catch leftover unmatched opening brackets like `"((("`.
- Handling an empty string or immediate closing bracket (e.g., `"]"`) requires guarding against stack underflow when popping.