###  PRINT ULTI COUNTING FROM N TO 1


N = int(input("Enter the number till you wants to display the counting"))

def print_N(n,i):
    if n < i:
        return
    print(n)
    n -= 1
    print_N(n,i)
    
print_N(N,1)