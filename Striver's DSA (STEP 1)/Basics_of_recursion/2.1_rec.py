###  PRINT NAME N TIMES USING RECURSION

N = int(input("Enter number of times name needs to be printed "))


def N_times_name(i,n):
    if i > n :                         ### BASE CONDITION 
        return
    print("RIYA GOEL")
    i += 1
    
    N_times_name(i , n)
   
    
N_times_name(1 , N)