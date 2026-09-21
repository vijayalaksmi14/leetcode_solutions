## Problem: Best Time to Buy and Sell Stock (Easy-Medium)
**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach
Used a greedy dynamic approach with a single iteration through the prices array. We continuously track the lowest price encountered so far (`min_price`) and evaluate the profit if sold on the current day (`prices[i] - min_price`), keeping track of the maximum profit seen.

### Complexity
- Time: $O(n)$ where $n$ is the number of days (length of prices array).
- Space: $O(1)$ auxiliary space as we only store `min_price` and `max_profit` variables.

### Notes
Handling decreasing price inputs correctly requires initializing maximum profit to 0 so no negative transactions are completed.