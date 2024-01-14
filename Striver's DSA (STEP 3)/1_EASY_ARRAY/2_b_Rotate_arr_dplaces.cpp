/// LEFT ROTATE AN ARRAY BY ONE PLACE (2ND VIDEO KA  CODE)

#include<iostream>    
using namespace std;

void rotation(int arr[], int n )
{
    int temp = arr[0];
    for(int i =1 ; i < n ; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
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

    rotation(arr, n);

    cout<< "Rotated array is ";

    for(int i =0 ; i < n ;i++ )
    {
        cout<< arr[i] << " " ;
    }                                                   
    
    return 0 ;
} 
