"""
Freelancer Task Scheduler: Maximizing Profit with Deadlines
============================================================================================
You are building a task scheduler for a freelance job portal. Each job on the platform has:

A unique job ID.
A deadline (the last day it can be completed).
A profit (how much money it pays if completed).
A freelancer can only work on one job per day, and each job takes exactly one day to complete.
 The goal is to schedule jobs such that the total profit is maximized, and no job is scheduled after its deadline.

You are given a list of jobs with their deadlines and profits. 
Your task is to return the maximum number of jobs that can be completed and the total profit earned.
"""

n = int(input())
jobs = []
for _ in range(n):
    parts = input().split()
    jobID = parts[0]
    deadline = int(parts[1])
    profit = int(parts[2])
    
    jobs.append([jobID,deadline,profit])

jobs.sort(key = lambda x: x[2], reverse=True)

max_deadline = 0
for job in jobs:
    if job[1] > max_deadline:
        max_deadline = job[1]

slots = [-1]* (max_deadline+1)
no_jobs = 0
total_profit = 0
for jobID, deadline, profit in jobs:
    for d in range(deadline, 0,-1):
        if slots[d] == -1:
            slots[d] = jobID
            no_jobs +=1
            total_profit +=profit
            break
print(no_jobs, total_profit)