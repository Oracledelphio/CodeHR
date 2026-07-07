"""
Generate All Combinations of k Numbers from 1 to n
You are designing a lottery number picker system where a user can select k numbers out of a total range from 1 to n. 
To help test and verify your system, you need to generate all possible combinations of these selections.

In combinatorics, combinations are unordered selections, meaning that [1, 2] is considered the same as [2, 1]. 
The goal is to list all possible unique sets where the order of selection does not matter.
"""
def generate_num(n,k):
    result =[]
    def backtrack(start, curr):
        if len(curr) == k:
            result.append(curr[:])
            return
        for i in range(start,n+1):
            curr.append(i)
            backtrack(i+1,curr)
            curr.pop()
    backtrack(1,[])
    return result

n, k = map(int,input().split())
permutations =generate_num(n,k)
print(permutations)