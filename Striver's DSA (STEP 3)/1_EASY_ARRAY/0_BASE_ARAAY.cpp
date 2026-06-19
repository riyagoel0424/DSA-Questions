#include<bits/stdc++.h>    
#include<iostream>
using namespace std;

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

    for(int i =0 ; i < n ;i++ )
    {
        cout<< arr[i] << " " << endl;
    }                                                      
    
    int arr1[10];
    cout << "SIZE OF ARRAY IN BYTES" << sizeof(arr1) << endl;
    cout << "LENGTH OF ARRAY" << sizeof(arr1) / sizeof(int) << endl;
    return 0 ;

} 