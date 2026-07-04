s =  input()
t = input()
m = len(s)
n = len(t)

dp  = [[0 for _ in range(n+1)] for _ in range(m+1)]

dp[0][0] = 0
for r in range(1,n+1):
    dp[r][0] = 0
for c in range(1,m+1):
    dp[0][c] = 0

for r in range(1,n+1):
    for c in range(1,m+1):
        if s[r-1] == t[c-1]:
            dp[r][c] = dp[r-1][c-1] + 1
        else:
            dp[r][c] = max(dp[r-1][c],dp[r][c-1])
print(dp[len(s)][len(t)])