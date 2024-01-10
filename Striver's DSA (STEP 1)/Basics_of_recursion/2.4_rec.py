### PRINT LINEARLY FROM 1 TO N WITHOUT USING I+=1 (USE BACK TRACKING)

N = int(input("Enter the number till you wants to display the counting"))

###  ISME TUM i,n lo ya na lo no role bcz n to khin use hi ni hora

### PRINT KI STATEMENT NEECHE LIKHI HAI RECURSION SE 

def print_N(i):
    if i < 1 :
        return
    
    print_N(i-1)
    print(i)
    
print_N(N)