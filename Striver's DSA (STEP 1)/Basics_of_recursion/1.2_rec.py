count = 0
def base_condition(count):
    if count == 4:
        return 
    print(count)
    count+=1
    base_condition(count)
    
base_condition(count)

    
     