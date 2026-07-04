arr = [3, 4, 13, 13, 13, 20, 40]
target = 13
left = 0 
answ = -1
right = len(arr)-1
while left <= right:
    mid = (left+right) // 2
    if arr[mid] == target:
        answ = mid
        left = mid + 1
    elif arr[mid] > target:
        right = mid -1
    elif arr[mid] < target:
        left = mid +1

print(answ)