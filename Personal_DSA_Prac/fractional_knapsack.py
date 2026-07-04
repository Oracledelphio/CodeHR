def fractional_knapsack(capacity,weights,values):
    items =[]
    for i in range(len(weights)):
        ratio = values[i]/weights[i]
        items.append((ratio,weights[i],values[i]))
    
    items.sort(key= lambda x: x[0], reverse= True)

    total_value = 0.0
    for ratio,weight, value in items:
        if capacity >= weight:
            capacity-=weight
            total_value +=value
        else:
            fraction = capacity/weight
            total_value += value * fraction
            capacity = 0
            break
    return total_value

# --- MAIN FUNCTION ---
if __name__ == "__main__":
    # Test Case Setup
    weights = [10, 20, 30]
    values = [60, 100, 120]
    knapsack_capacity = 50
    
    print("--- Starting Fractional Knapsack ---")
    print(f"Max Capacity: {knapsack_capacity}")
    print(f"Weights available: {weights}")
    print(f"Values available:  {values}")
    print("-" * 34)
    
    # Execute the algorithm
    max_profit = fractional_knapsack(knapsack_capacity, weights, values)
    
    print("-" * 34)
    print(f"Maximum value we can obtain = {max_profit}")
