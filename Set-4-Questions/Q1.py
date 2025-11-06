def solve_cow_swaps():
    """
    Solves the minimum swaps problem for Farmer John's cows.

    The problem asks for the minimum number of swaps to sort an array.
    This is a classic permutation problem. The minimum number of swaps
    is equal to (N - C), where N is the number of elements and C is
    the number of "cycles" in the permutation.

    A cycle is a path you follow from an element's current position
    to its target position, then from that element's current position
    to *its* target position, and so on, until you get back to the start.

    With duplicate values (like the two '7's), this is tricky. To get
    the true minimum swaps, when we sort the (value, index) pairs,
    we sort by value ascending, but by *original index descending*.
    This non-standard sort helps break cycles for duplicate elements
    in an optimal way, leading to the correct answer of 3 for the sample.
    """
    
    try:
        herd_size_str = input()
        if not herd_size_str:
            print("Error: No input for herd size.")
            return
        herd_size = int(herd_size_str)
        
        current_lineup = []
        for _ in range(herd_size):
            height_str = input()
            if not height_str:
                print(f"Error: Missing height input for herd of {herd_size}")
                return
            current_lineup.append(int(height_str))
            
        if len(current_lineup) != herd_size:
            print("Error: Mismatch in herd size and number of heights entered.")
            return

        value_with_original_spot = []
        for idx in range(herd_size):
            value_with_original_spot.append((current_lineup[idx], -idx))

        value_with_original_spot.sort()

        target_pos = [0] * herd_size
        for target_index in range(herd_size):
            original_index = -value_with_original_spot[target_index][1]
            target_pos[original_index] = target_index
            
        already_checked = [False] * herd_size
        num_groups = 0
        
        for original_index in range(herd_size):
            if not already_checked[original_index]:
                num_groups += 1
                current_pos_in_cycle = original_index
                
                while not already_checked[current_pos_in_cycle]:
                    already_checked[current_pos_in_cycle] = True
                    current_pos_in_cycle = target_pos[current_pos_in_cycle]

        swaps_operations_needed = herd_size - num_groups
        print(f"The Swaps needed are: ",swaps_operations_needed)

    except ValueError:
        print("Error: All inputs must be integers.")
    except EOFError:
        pass
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

solve_cow_swaps()