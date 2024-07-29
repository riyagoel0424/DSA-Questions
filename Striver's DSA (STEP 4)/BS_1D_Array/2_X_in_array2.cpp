///  BINARY SEARCH TO FIND X IN SORTED ARRAY
///  USING RECURSION

# include <iostream>
using namespace std;

int to_find_X(int arr[], int low ,int high , int X ){

    if (low > high)
    {
        return -1;
    }
    int mid = (low+high) / 2;
    if(arr[mid] == X)
    {
        return mid;
    }
    else if(X > arr[mid])
    {
        return to_find_X(arr, mid+1 , high , X );
    }
    else 
    {
        return to_find_X(arr, low , mid-1 , X );
    }
    

}


int main(){
    int n ;
    cout << "The number of elements in an array " << endl ;
    cin >> n ;
    int arr[n];
    cout << "Now write the elements of the array " <<endl ;
    for(int i = 0 ; i < n ;i++)
    {
        cin >> arr[i] ;
    }                                                           /// int main se yha tk just array input kraya hai
    
    int X , low ,high ;
    cout << "ELEMENT WHICH NEEDS TO BE FOUND IN  SORTED ARRAY " << endl;
    cin >> X ;
    low = 0;
    high = n-1;

    cout << to_find_X( arr, low, high, X );                                       /// upar likha function call hua hai
    
    return 0 ;
} 