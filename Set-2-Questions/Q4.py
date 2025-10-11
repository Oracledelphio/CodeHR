n = int(input("Enter the value of n: "))
nums = list(map(int , input("Enter the numbers: ").split()))

pos = [0] * (n + 1)
for i in range(n):
    pos[nums[i]] = i

rounds = 1
for i in range(1, n):
    if pos[i + 1] < pos[i]:
        rounds += 1

print(rounds)
