"""
Mission Backpack: Find the Secret Subset
===========================================================
You are given a list of artifacts, each with a weight value.

Your goal is to determine if there is a subset of artifacts such that the total weight equals a given target weight.

You can either include or exclude each artifact individually.

Return True if such a subset exists, otherwise return False.
"""

n, target = map(int,input().split())
weights = list(map(int,input().split()))

dp = [[False for _ in range(target+1)] for _ in range(n+1)]

for i in range(n+1):
    dp[i][0] = True

for i in range(1,n+1):
    for s in range(1,target+1):
        dp[i][s] = dp[i-1][s]

        if weights[i] <= target:
            dp[i][s] = dp[i][s] or dp[i-1][s-weights[i-1]]
print(str(dp[n][target]).lower())