def Kadane():
    arr = [-2,5,6,-12,8,1,9,-8]
    curr = arr[0]
    best = arr[0]
    for i in range(1,len(arr)):
        curr = max(arr[i], curr+arr[i])
        best = max(best,curr)
    return best

result = Kadane()
print(result)