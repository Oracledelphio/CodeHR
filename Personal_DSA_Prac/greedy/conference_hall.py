"""
Conference Hall Manager: Optimal Activity Scheduling
===============================================================================
You are the event coordinator of a large conference center. Multiple activities are scheduled throughout the day, 
and each activity has a start time and an end time. However, the venue has only one hall, so no two activities can overlap.

Your goal is to select the maximum number of non-overlapping activities that can be scheduled in the hall.

You are given the start and end times of n activities. Write a program to choose the maximum number of activities that can be 
performed by a single person or in one room, 
assuming a person/room can only work on a non-overlapping schedule.
"""

n = int(input())
overlaping =[]
for _ in range(n):
    start, end = map(int,input().split())
    overlaping.append([start,end])

overlaping.sort(key = lambda x: x[1])

count = 0
last_end_time = -1
for i in overlaping:
    current_start = i[0]
    current_end = i[1]
    if current_start >= last_end_time:
        count+=1
        last_end_time = current_end

print(count)