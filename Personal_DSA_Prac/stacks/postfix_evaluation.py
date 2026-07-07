s = input()
stack = []
operator = ['*','/','+','-']
for ch in s:
    if ch not in operator:
        stack.append(int(ch))
    else:
        if ch == "*":
            a = stack.pop()
            b = stack.pop()
            stack.append(a*b)
        elif ch == "/":
            a = stack.pop()
            b = stack.pop()
            stack.append(a//b)
        elif ch == "+":
            a = stack.pop()
            b = stack.pop()
            stack.append(a+b)
        elif ch == "-":
            a = stack.pop()
            b = stack.pop()
            stack.append(a-b)
        else:
            print("Not a valid operator!")

print(stack[0])

