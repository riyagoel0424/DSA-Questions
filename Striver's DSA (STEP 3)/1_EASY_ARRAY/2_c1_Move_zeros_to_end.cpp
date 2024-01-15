///     BRUTE WAY    ///
///  MOVE ZEROS AT THE END OF ARRAY (2ND VIDEO KA 3rd CODE)

#include<iostream>
#include<vector>    
using namespace std;

void zeros_to_end(int arr[], int n )
{
    vector<int> temp;

    for(int i =1 ; i < n ; i++)
    {
        if(arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    
    int size =  temp.size();
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = temp[i];
    }

    for(int i = size ; i < n ;i++)
    {
        arr[i] = 0;
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
