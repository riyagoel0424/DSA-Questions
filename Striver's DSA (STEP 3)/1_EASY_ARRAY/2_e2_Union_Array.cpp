/// UNION OF SORTED ARRAY /// OPTIMAL SOLUTION
/// YE MENE ABHI NHI KIA ... NA ISKE BAAD VALA INTERSECTION OF TWO ARRAY KIA HAI ...

#include<bits/stdc++.h>    
#include<iostream>
using namespace std;

//// I HAVE NOT DONE THIS YET /// MENE ISKE BAAD KA INTERSECTION OF TWO ARRAYS BHI NHI KIA

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
        cout<< arr[i] << " " ;
    }                                                      
    
    return 0 ;
}