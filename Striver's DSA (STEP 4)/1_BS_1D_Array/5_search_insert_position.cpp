 ///  TO FIND TARGET IN SORTED ARRAY 
///  IF TARGET IS NOT PRESENT THEN INSERT THE TARGET IN THE SORTED IN ARRAY AT RIGHT POSITION
///  THIS IS JUST LIKE LOWER BOUND VALA QUES

# include <iostream>
using namespace std;

int to_search_insert_target(int arr[] , int n , int X )
{
    int low , high , mid ;
    low = 0;
    high = n-1;
    int ans ;
    
    while(low <= high)
    {
        int mid = (low + high)/2 ;
        if(arr[mid] >= X)
        {
            ans = mid ;
            high = mid - 1;
        }
        else              
        {
            low = mid + 1;
        }
        
    }
    
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

    cout << to_search_insert_target(arr , n ,  X );


}