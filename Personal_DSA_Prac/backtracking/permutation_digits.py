"""
Generate All Possible Permutations of Distinct Integers
=================================================================
You are building a shuffling feature for a puzzle game where a player is given a sequence of distinct numbers, 
and you need to generate all possible unique arrangements (permutations) of these numbers to present as possible game states.
 Given an array of distinct integers, your task is to generate and return all the possible permutations.

This problem is critical in combinatorial algorithms, testing frameworks, and games where all orderings of input data need to be explored.


"""

def generate_nums(nums):
    result=[]
    def backtrack(current_path):
        if len(current_path) == len(nums):
            result.append(current_path[:])
            return 
        
        for num in nums:
            if num not in current_path:
                current_path.append(num)
                backtrack(current_path)
                current_path.pop()
    backtrack([])
    return result

if __name__ == "__main__":
    n = int(input().strip())
    nums = list(map(int,input().split()))
    permutations = generate_nums(nums)
    print(permutations)