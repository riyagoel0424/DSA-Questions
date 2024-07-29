/// BINARY SEARCH HMESHA SORTED ARRAY MEIN HI HOTA HAI ... 
/// OR WE CAN SAY IN SORTED SEARCH SPACE
///  BINARY SEARCH TO FIND X IN SORTED ARRAY 
///  USING ITERATION

# include <iostream>
using namespace std;

int to_find_X(int arr[], int n ,int X ){

    int low , high , mid ;
    low = 0;
    high = n-1;
    while(low<=high)          /// YE HMARA SEARCH SPACE HAI
    {
        mid = (low + high) / 2;
        if(arr[mid] > X)
        {
            // low = 0;..............   1
            high = mid -1;
        }
        else if(arr[mid] < X)
        {
            low = mid + 1;
            // high = n-1; ............. 2   
        }
    /// YE 1 AND 2 LIKHNE SE HUM BAAR BAAR LOW KO 0 OR HIGH KO N-1 SET KR RE TO TIME COMPLEXITY BDH RI HAI  
        else{
            return mid;
        }
    }
    return -1;                /// WHEN THE ELEMENT IS NOT FOUNT IN ARRAY
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
    
    int X ;
    cout << "ELEMENT WHICH NEEDS TO BE FOUND IN  SORTED ARRAY " << endl;
    cin >> X ;

    cout << to_find_X( arr,  n , X );                                       /// upar likha function call hua hai
    
    return 0 ;
} 