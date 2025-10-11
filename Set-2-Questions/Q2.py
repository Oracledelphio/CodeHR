a,b,x,y = map(int, input("Enter the integer values: ").split())
direct = abs(a-b)
teleporter_1 = abs(a-x) + abs(b-y)
teleporter_2 = abs(a-y) + abs(b-x)

print(min(direct, teleporter_1, teleporter_2))