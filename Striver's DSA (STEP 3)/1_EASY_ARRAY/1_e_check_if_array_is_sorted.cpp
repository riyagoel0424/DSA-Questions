/// TO CHECK WHETHER THE ARRAY IS SORTED OR NOT (1ST VIDEO KA 3RD CODE)

#include<bits/stdc++.h>    
using namespace std;

char is_array_sorted(int arr[], int n )
{
    for(int i = 1 ; i < n ;i++)
    {
        if(arr[i] >= arr[i-1])
        {
            
        }
        else
        {
            return false ;
        }
    }
    return true ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////


int is_array_sorted2(int arr[], int n )
{
    for(int i = 0 ; i < n-1 ; i++)        /// n-1 lia bcz jbb i = n-2 hoga tbb i+1 = n-1 hoga .... agr i < n lia then i+1 = n hoga which is out of bound
    {
        if(arr[i]>arr[i+1])
        {
            return 0;
        }
    }
    return 1 ;
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
    }      

    cout << is_array_sorted( arr, n );
    cout << is_array_sorted2( arr, n );

    return 0;
}