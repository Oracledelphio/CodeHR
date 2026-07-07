"""
Balanced Parentheses Combinations Generator
=========================================================
You are designing a code editor’s 
autocomplete feature that assists developers by suggesting all valid arrangements of balanced parentheses when they type a pair. 
Given n pairs of parentheses, you need to generate all possible valid combinations of well-formed parentheses,
 where every opening bracket '(' has a corresponding closing bracket ')' and no closing bracket appears before its matching opening.

This task is useful for generating valid mathematical expressions, compiler design, and solving combinatorial problems in programming tools.
"""

def generate_paranthesis(n):
    result = []
    def backtracking(current_path, open_path, close_path):
        if len(current_path) == 2*n:
            result.append("".join(current_path))
            return
        if open_path < n:
            current_path.append("(")
            backtracking(current_path, open_path+1,close_path)
            current_path.pop()
        if close_path  < open_path:
            current_path.append(")")
            backtracking(current_path, open_path, close_path+1)
            current_path.pop()
    backtracking([],0,0)
    return result

if __name__ == "__main__":
    n = int(input().strip())
    combination = generate_paranthesis(n)
    print("["+", ".join(combination)+"]")
    
