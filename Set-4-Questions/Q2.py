def solve_apartment_matching():
    """
    Solves the apartment matching problem using a two-pointer technique.

    The most efficient way to solve this is to sort both the applicants'
    desired sizes and the available apartment sizes. Then, we use two
    pointers to walk through both lists simultaneously.
    """
    
    try:
        first_line = input().split()
        if len(first_line) != 3:
            print("Error: Expected 3 numbers on the first line.")
            return
            
        num_applicants = int(first_line[0])
        num_apartments = int(first_line[1])
        tolerance = int(first_line[2])

        applicant_requests_line = input().split()
        if len(applicant_requests_line) != num_applicants:
            print(f"Error: Expected {num_applicants} applicant sizes.")
            return
        applicant_requests = [int(size) for size in applicant_requests_line]

        available_sizes_line = input().split()
        if len(available_sizes_line) != num_apartments:
            print(f"Error: Expected {num_apartments} apartment sizes.")
            return
        available_sizes = [int(size) for size in available_sizes_line]
        applicant_requests.sort()
        available_sizes.sort()

        applicant_idx = 0  
        apartment_idx = 0
        successful_placements = 0

        while applicant_idx < num_applicants and apartment_idx < num_apartments:
            
            current_applicant_wish = applicant_requests[applicant_idx]
            current_apartment_size = available_sizes[apartment_idx]

            min_acceptable = current_applicant_wish - tolerance
            max_acceptable = current_applicant_wish + tolerance

            if current_apartment_size < min_acceptable:
                apartment_idx += 1
                
            elif current_apartment_size > max_acceptable:
                applicant_idx += 1
                
            else:
                successful_placements += 1
                applicant_idx += 1
                apartment_idx += 1

        print(successful_placements)

    except ValueError:
        print("Error: All inputs must be integers.")
    except EOFError:
        pass 
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

solve_apartment_matching()