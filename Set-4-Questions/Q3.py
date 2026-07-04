def solve_ferris_wheel():
    try:
        first_line = input().split()
        if len(first_line) != 2:
            print("Error: Expected 2 numbers on the first line.")
            return
            
        child_count = int(first_line[0])
        max_weight_limit = int(first_line[1])

        weights_line = input().split()
        if len(weights_line) != child_count:
            print(f"Error: Expected {child_count} child weights.")
            return
        child_weights = [int(w) for w in weights_line]

        child_weights.sort()

        light_pointer = 0
        heavy_pointer = child_count - 1
        gondolas_used = 0

        while light_pointer <= heavy_pointer:
            
            gondolas_used += 1
            lightest_weight = child_weights[light_pointer]
            heaviest_weight = child_weights[heavy_pointer]
            if light_pointer != heavy_pointer and \
               lightest_weight + heaviest_weight <= max_weight_limit:

                light_pointer += 1
            heavy_pointer -= 1

        print(f"Number of Gondolas used: ",gondolas_used)

    except ValueError:
        print("Error: All inputs must be integers.")
    except EOFError:
        pass
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

solve_ferris_wheel()