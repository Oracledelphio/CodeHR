n,x = map (int, input("Enter the values of n x: ").split())
nums = list(map(int, input("Enter the numbers: ").split()))
positions= []
flag = False
for i in nums:
    if x-i in nums:
        positions.append((nums.index(i)+1,nums.index(x-i)+1))
        flag = True
if flag:
    print(positions[0][0], positions[0][1])
else:
    print("IMPOSSIBLE")
