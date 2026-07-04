def quicksort(arr):
    if len(arr) <=1:
        return arr
    p = arr[len(arr)//2]

    l = [x for x in arr if x < p]
    r = [x for x in arr if x > p]
    m = [x for x in arr if x == p]

    return quicksort(l) + m + quicksort(r)

arr = [5,12,2,9,34,24]
print(quicksort(arr))