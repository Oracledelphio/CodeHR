"""
Smart Railway Station Minimum Platforms for Train Scheduling

A smart railway station is trying to automate platform allocation for arriving trains. 
Each train arrives at a specific time and remains at the station for a certain number of seconds. 
The station must accommodate all trains such that no train waits.

"""

n = int(input())
arrivals =[]
departures = []
for _ in range(n):
    arrival, stop = map(int,input().split())
    arrivals.append(arrival)
    departures.append(arrival+stop)

arrivals.sort()
departures.sort()

i=0
j=0

max_platforms =0
platforms = 0
while i < n and j < n:
    if arrivals[i] < departures[i]:
        platforms+=1
        i+=1
        if platforms > max_platforms:
            max_platforms = platforms
    else:
        platforms-=1
        j+=1

print(max_platforms)
