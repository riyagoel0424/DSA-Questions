/// LEFT ROTATE AN ARRAY BY ONE PLACE (2ND VIDEO KA  CODE)

#include<iostream>    
using namespace std;

void zeros_to_end(int arr[], int n )
{
    int temp[100];

    for(int i =1 ; i < n ; i++)
    {
        int j =0;
        if(arr[i] == 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }
    
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

    zeros_to_end(arr, n);

    cout<< "THE RESULTANT ARRAY IS ";

    for(int i =0 ; i < n ;i++ )
    {
        cout<< arr[i] << " " ;
    }                                                   
    
    return 0 ;
} 
