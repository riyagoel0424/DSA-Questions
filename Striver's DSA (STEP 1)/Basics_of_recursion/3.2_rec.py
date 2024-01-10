### SUM OF FIRST N NUMBERS USING RECURSION

### (FUNCTIONAL WAY) 

N = int(input("Enter a number "))

def summation(n):
    if n == 0:
        return 0         ### RETURN 0 KRNA ZROORI HAI BCZ VRNA RETURN NONE HOTA HAI PR ADD KRNE KE LIYE SAME DATA TYPE KE LIYE 0                                
    
    return n + summation(n-1)

print(summation(N))