"""
Why Greedy Fails Here:
If you take the item with the highest value, it might be so heavy it blocks you 
from taking 3 lighter items that sum to a greater value.
If you take items with the highest value-to-weight ratio, you might leave empty 
space in the bag that could have been filled by a slightly worse-ratio item.
Therefore, we must evaluate ALL combinations intelligently using DP.
"""

def solve_knapsack(weights, values, capacity):
    n = len(weights)
    
    # STEP 1: Create the DP Table (Tabulation)
    # dp[i][w] will represent the maximum value we can achieve using ONLY 
    # the first 'i' items, with a maximum knapsack capacity of 'w'.
    # 
    # Dimensions: (n + 1) rows by (capacity + 1) columns.
    # We add +1 to handle the base cases (0 items available, or 0 capacity).
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    
    # STEP 2: Build the table from bottom up
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            
            # Note: i is 1-indexed for the DP table, so the current item's 
            # weight and value are at index (i - 1) in the input arrays.
            current_weight = weights[i - 1]
            current_value = values[i - 1]
            
            # The Decision Point: Pick or Don't Pick?
            
            # Scenario A: The item is too heavy for the current capacity 'w'.
            if current_weight > w:
                # We CANNOT pick it. The best we can do is whatever the best 
                # was using the previous items (i-1) at this exact same capacity.
                dp[i][w] = dp[i - 1][w]
                
            # Scenario B: The item CAN fit in the bag.
            else:
                # Choice 1: Leave it. (Same as above)
                value_if_left = dp[i - 1][w]
                
                # Choice 2: Take it.
                # If we take it, we gain 'current_value'. 
                # BUT, it takes up 'current_weight' space. 
                # So we must add its value to the maximum value we could have achieved 
                # with the REMAINING capacity (w - current_weight) using the previous items.
                value_if_taken = current_value + dp[i - 1][w - current_weight]
                
                # We want the MAXIMUM of these two choices!
                dp[i][w] = max(value_if_left, value_if_taken)
                
    # The final answer is located at the bottom-right of the table:
    # "The max value using ALL 'n' items with the FULL 'capacity'"
    return dp[n][capacity]

# --- Let's test it to visualize the DP in action ---
if __name__ == "__main__":
    item_weights = [1, 3, 4, 5]
    item_values  = [1, 4, 5, 7]
    max_capacity = 7
    
    max_profit = solve_knapsack(item_weights, item_values, max_capacity)
    print(f"Maximum Profit achievable: {max_profit}")
    
    # To truly understand this, trace dp[i][w] mentally.
    # When evaluating the 5-weight item (value 7) at capacity 7:
    # Choice 1 (Leave): Best profit with previous items at cap 7 is 9 (items w=3 + w=4).
    # Choice 2 (Take): Value 7 + Best profit at cap (7-5=2) with prev items. 
    #                  Best at cap 2 is 1 (the w=1 item). Total = 7 + 1 = 8.
    # max(9, 8) = 9. 
    # DP perfectly realizes leaving the highest value item yields a better overall result!