///     OPTIMAL WAY    ///  BCZ HERE WE ARE NOT USING ANY EXTRA SPACE LIKE IN BRUTE WAY
/// LEFT ROTATE AN ARRAY BY D PLACES (2ND VIDEO KA 1ST CODE)

#include<bits/stdc++.h>
#include <algorithm>                  /// TO IMPORT INVERSE FUNCTION 
#include<iostream>    
using namespace std;

void rotation(int arr[], int n , int D)
{   
    D = D % n;
    reverse(arr , arr+D);
    reverse(arr+D , arr+n);
    reverse(arr , arr+n);

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

    int D;
    cout<<"Enter the value of D " << endl;
    cin >> D;

    rotation(arr, n , D);

    cout<< "Rotated array is ";

    for(int i =0 ; i < n ;i++ )
    {
        cout<< arr[i] << " " ;
    }                                                   
    
    return 0 ;
} 
