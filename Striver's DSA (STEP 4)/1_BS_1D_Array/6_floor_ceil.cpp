///  TO FIND THE FLOOR AND CEIL IN AN SORTED ARRAY USING BINARY SEARCH 
///  FLOOR ----->  LARGEST NO. IN ARRAY <= TARGET
///  CEIL  ---->  SMALLEST NO. IN ARRAY >= TARGET     (LOWER BOUND)

# include <iostream>
using namespace std;

int to_find_floor(int arr[] , int n , int X )
{
    int low , high , mid ;
    low = 0;
    high = n-1;
    int floor ;
    

    while(low <= high)
    {
        int mid = (low + high)/2 ;
        if(arr[mid] <= X)
        {
            floor = arr[mid];
            low = mid + 1;
            
        }
        else               ////  arr[mid] < X
        {
            high = mid - 1;  
        }
    }
    return floor;
}

int main(){
    int n ;
    cout << "The number of elements in an array " << endl ;
    cin >> n ;
    int arr[n];
    cout << "Now write the elements of the array in sorted manner" <<endl ;
    for(int i = 0 ; i < n ;i++)
    {
        cin >> arr[i] ;
    }                                                           /// int main se yha tk just array input kraya hai

    int X ;   /// target
    cout << "Number for which lower bound to be searched" << endl;
    cin >> X ;

    cout << to_find_floor(arr , n ,  X );


}       
