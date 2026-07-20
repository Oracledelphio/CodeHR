def infix_to_postfix(expression):
    precedence = {
        '^': 3,
        '*': 2,
        '/': 2,
        '+': 1,
        '-': 1
    }

    stack = []
    output = []

    for ch in expression:

        if ch.isalnum():
            output.append(ch)

        elif ch == '(':
            stack.append(ch)

        elif ch == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()

        else:
            while (stack and stack[-1] != '(' and
                   precedence.get(stack[-1], 0) >= precedence.get(ch, 0)):
                output.append(stack.pop())
            stack.append(ch)

    while stack:
        output.append(stack.pop())

    return "".join(output)


expr = "A+B*(C-D)"
print(infix_to_postfix(expr))