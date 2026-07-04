"""
Smart Thief: Maximum Loot
==============================================================================
A smart thief wants to rob houses along a street. Each house has some amount of money hidden inside, represented by an array. 
However, the thief cannot rob adjacent houses because the security system will alert the police.
Given an array representing the amount of money at each house, determine the maximum amount of money the thief can rob without alerting the police.
"""

n = int(input())
houses = list(map(int,input().split()))

if n == 0:
    print(0)
elif n == 1:
    print(houses[0])
else:
    dp = [0] * n
    dp[0] = houses[0]
    dp[1] = max(houses[0],houses[1])

    for i in range(2,n):
        dp[i] = max(houses[i] + dp[i-2], dp[i-1])
    print(dp[-1])
