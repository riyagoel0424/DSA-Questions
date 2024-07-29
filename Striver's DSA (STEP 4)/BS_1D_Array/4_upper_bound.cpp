///  TO FIND THE UPPER BOUND IN AN SORTED ARRAY USING BINARY SEARCH 

# include <iostream>
using namespace std;

// int to_find_UB(int arr[] , int n , int X )
// {
//     int low , high , mid ;
//     low = 0;
//     high = n-1;
//     int Upper_bound = -1;
    

//     while(low <= high)
//     {
//         int mid = (low + high)/2 ;
//         if(arr[mid] <= X)
//         {
//             Upper_bound = mid;
//             low = mid + 1;
//         }
//         else               ////  arr[mid] < X
//         {
//             high = mid - 1;
//         }
//     }
//     return Upper_bound;
// }

int to_find_UB(int arr[] , int n , int X )
{
    int low , high , mid ;
    low = 0;
    high = n-1;
    int Upper_bound = n;
    

    while(low <= high)
    {
        int mid = (low + high)/2 ;
        if(arr[mid] > X)
        {
            Upper_bound = mid;
            high = mid - 1;
        }
        else               ////  arr[mid] <= X
        {
            low = mid + 1;
        }
    }
    return Upper_bound;
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
    cout << "Number for which upper bound to be searched" << endl;
    cin >> X ;

    cout << to_find_UB(arr , n ,  X );


}