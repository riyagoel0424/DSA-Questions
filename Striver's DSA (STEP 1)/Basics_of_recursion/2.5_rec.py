### PRINT FROM N TO 1 WITHOUT USING I-=1 (USE BACK TRACKING)

N = int(input("Enter the number till you wants to display the counting"))


def print_N(i,n):
    if i > n :
        return
    
    print_N(i+1,n)
    print(i)
    
print_N(1,N)