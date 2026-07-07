"""
Emergency Supply Drone: Maximizing Resource Value Delivery    

You are designing a software system for emergency supply drones that deliver aid during natural disasters. 
Each drone has a limited weight capacity and must be loaded with the most valuable combination of resources (food, medicine, etc.).

Each supply item has:

A weight.
A value (representing usefulness or market price).
The drone can carry fractions of items if needed. 
Your task is to write a function to determine the maximum total value that can be carried in the drone without exceeding its weight limit.

Given the weights and values of n items and a drone capacity W, 
return the maximum value that can be carried in the knapsack using fractional parts of items if necessary.

"""

def fractional_knapsack(capacity, weights, values):
    items = []
    n = len(weights)
    for i in range(n):
        ratio = values[i] / weights[i]
        items.append([ratio,weights,values])
    
    items.sort(key = lambda x: x[0], reverse= True)

    total_profit = 0
    for ratio, weight, value in items:
        if capacity >= weight:
            total_profit +=property
            capacity -= weight
        else:
            fraction = capacity/weight
            total_profit += value * fraction
            capacity = 0
            break
    print(f"{total_profit:.2f}")
    