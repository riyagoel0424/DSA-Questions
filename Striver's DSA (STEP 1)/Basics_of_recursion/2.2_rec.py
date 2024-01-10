### PRINT LINEARLY FROM 1 TO N USING RECURSION

N = int(input("Enter the number till you wants to display the counting"))

def print_N(i,n):
    if i > n :
        return
    print(i)
    i += 1
    print_N(i,n)
    
print_N(1,N)
        