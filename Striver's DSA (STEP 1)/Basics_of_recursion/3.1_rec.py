### SUM OF FIRST N NUMBERS USING RECURSION

### (PARAMETERISED WAY) 

N = int(input("Enter a number "))


def summation(i,sum):
    if i < 1:
        print(sum)
        return               ###  IF WE WILL NOT USE RETURN OVER HERE THEN JBB I = 0 HOGA TBB IF VALI STATEMENT CHLE KE BAAD BHI FUNCTION
                             ###  CALL HOGA OR I -1 MEIN CHLA JAYEGA NAD SO ON . INFINITE RECURSION 
    sum += i
    summation(i-1 , sum)
    
summation(N, 0)