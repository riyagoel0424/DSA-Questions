/// LINEAR SEARCH   /// THE INDEX OF FIRST OCCURRENCE OF GIVEN NUMBER

#include<bits/stdc++.h>    
#include<iostream>
using namespace std;

int linear_search(int arr[] , int n , int num)
{
    for(int i =0 ; i < n ; i++)
    {
        if(arr[i] == num)
        {
            return i ; 
        }
       
    }
    return -1 ;       /// IF NUM DOES NOT LIE IN ARRAY THEN RETURN -1
}

int main()
{
    int n ;
    cout << "The number of elements in an array " << endl ;
    cin >> n ;
    int arr[n];
    cout << "Now write the elements of the array " <<endl ;
    for(int i = 0 ; i < n ;i++)
    {
        cin >> arr[i] ;
    }     

    int num ;
    cout << "ENTER THE NUMBER YOU WANNA SEARCH" << endl;
    cin >> num;

    cout<<"THE INDEX OF FIRST OCCURRENCE OF NUM IS " ;              
    cout <<  linear_search(arr , n , num);                                 

    return 0 ;
}