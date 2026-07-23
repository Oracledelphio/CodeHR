#include <vector>
#include <algorithm>
using namespace std;

int solve_knapsack_1D(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    
    // Size is capacity + 1. Memory is now O(W) instead of O(N*W).
    // For W = 100,000, this is just 400 KB of RAM!
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        int current_weight = weights[i];
        int current_value = values[i];
        
        // Loop BACKWARDS to prevent using the same item multiple times
        for (int w = capacity; w >= current_weight; w--) {
            // Choice 1 (Leave it): dp[w] remains unchanged
            // Choice 2 (Take it): current_value + dp[w - current_weight]
            dp[w] = max(dp[w], current_value + dp[w - current_weight]);
        }
    }

    return dp[capacity];
}