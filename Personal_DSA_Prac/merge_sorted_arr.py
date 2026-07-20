def merge(a,b):
    l1 = 0
    l2 = 0
    result = []
    while l1 < len(a) and l2 < len(b):
        if a[l1] < b[l2]:
            result.append(a[l1])
            l1+=1
        else:
            result.append(b[l2])
            l2+=1
    if l1 < len(a):
        result.extend(a[l1:])
    else:
        result.extend(b[l2:])
    return result

a = [1,5,7,12,22]
b = [2,3,11,17,21,45,63]
res = merge(a,b)
print(res)

