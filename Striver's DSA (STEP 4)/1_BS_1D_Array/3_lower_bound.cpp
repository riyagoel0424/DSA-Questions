///  TO FIND THE LOWER BOUND IN AN SORTED ARRAY USING BINARY SEARCH 

# include <iostream>
using namespace std;

int to_find_LB(int arr[] , int n , int X )
{
    int low , high , mid ;
    low = 0;
    high = n-1;
    int Lower_bound = n;   // n is size of array 
// assume lb = n in start bcz agr lb array mein nhi mila then vo n hi hoga  

    while(low <= high)
    {
        int mid = (low + high)/2 ;
        if(arr[mid] >= X)
        {
            Lower_bound = mid; // n ko replace kr re hai better value se jiske lb hone ke chance zyada hai
            high = mid - 1;
        }
        else               ////  arr[mid] < X
        {
            low = mid + 1;
        }
    }
    return Lower_bound;
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

    cout << to_find_LB(arr , n ,  X );


}       
