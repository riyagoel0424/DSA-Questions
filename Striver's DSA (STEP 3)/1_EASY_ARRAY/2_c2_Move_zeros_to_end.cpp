///     OPTIMAL WAY    ///  BCZ HERE WE ARE NOT USING ANY EXTRA SPACE LIKE IN BRUTE WAY
///  MOVE ZEROS AT THE END OF ARRAY (2ND VIDEO KA 3rd CODE)

#include<iostream>
#include<vector>    
using namespace std;

void zeros_to_end(int arr[], int n )
{
    int j = -1 ;
    for(int i = 0; i < n; i++)  /// SABSE PHLE J POINTER KO USS INDEX PR LEKR JAO JHAA FIRST 0 AAYA HAI IN THE ARRAY
    {
        if(arr[i] == 0)
        {
            j = i ;
            break ;
        }
    }

    for(int i = j+1 ; i < n ; i++)   /// J AND I DONO POINTER KO MOVE KRENGE & J HMESHA UNN INDEX PR RHEGA JHA 0 HAI
    {
        if(arr[i] != 0)
        {
            swap(arr[i] , arr[j]);
            j++ ;
        }
    }
 
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

    zeros_to_end(arr, n);

    cout<< "THE RESULTANT ARRAY IS ";

    for(int i =0 ; i < n ;i++ )
    {
        cout<< arr[i] << " " ;
    }                                                   
    
    return 0 ;
} 
