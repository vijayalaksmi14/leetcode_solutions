#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0; // Cannot buy and sell if less than 2 days
    }

    int min_price = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        // Update the minimum price seen so far
        if (prices[i] < min_price) {
            min_price = prices[i];
        } 
        // Calculate profit if sold today and update max_profit
        else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
        }
    }

    return max_profit;
}

// Local testing main block
int main() {
    // Typical test case: Buy at 1, sell at 6 -> Profit = 5
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Test 1 (prices = [7,1,5,3,6,4]): %s (Profit: %d)\n", 
           maxProfit(prices1, n1) == 5 ? "PASSED" : "FAILED", maxProfit(prices1, n1));

    // Edge test case: Monotonically decreasing (no profit possible)
    int prices2[] = {7, 6, 4, 3, 1};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Test 2 (prices = [7,6,4,3,1]): %s (Profit: %d)\n", 
           maxProfit(prices2, n2) == 0 ? "PASSED" : "FAILED", maxProfit(prices2, n2));

    return 0;
}