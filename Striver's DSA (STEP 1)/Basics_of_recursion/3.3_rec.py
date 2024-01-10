### FACTORIAL OF A NUMBER N USING RECURSION

### (FUNCTIONAL WAY)


N = int(input("Enter a number "))

def factorial(n):
    if n == 1:
        return 1         ### RETURN 1 KRNA ZROORI HAI BCZ VRNA ANS WILL BE 0 ALWAYS
    
    return n * factorial(n-1)

print(factorial(N))