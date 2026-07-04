year =  int(input())
if (year/4)*4 == year:
    if (year/100)*100 == year:
        if (year/400)*400 == year:
            print("Leap Year")
        else:
            print("Not a Leap Year")
    else:
        print("Leap Year")