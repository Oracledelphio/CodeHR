"""
Robot’s Grid Navigation Challenge
=============================================================
A robot is placed in the top-left corner of an m x n grid.
It can move only right or down from its current cell.
Your task is to compute the total number of unique paths the robot can take to reach the bottom-right corner of the grid.
"""

m , n = map(int,input().split())
grid = [[0 for _ in range(n)] for _ in range(m)]

grid[0][0] = 1

for r in range(m):
    grid[r][0] = 1
for c in range(n):
    grid[0][c]

for r in range(m):
    for c in range(n):
        grid[r][c] = grid[r][c-1] + grid[r-1][c]

print ( grid[m-1][n-1])
