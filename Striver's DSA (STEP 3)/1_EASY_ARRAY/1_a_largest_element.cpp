/// LARGEST ELEMENT IN A ARRAY (1ST VIDEO KA 1ST CODE )

# include <iostream>
using namespace std;

void largest_num_in_arr(int arr[], int n )
{
    int largest = arr[0];
    for(int i = 1 ; i < n ; i++)
    {
        if( arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "The largest number in array is " << largest ;
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
    }                                                           /// int main se yha tk just array input kraya hai
    largest_num_in_arr( arr,  n );                              /// upar likha function call hua hai
    
    return 0 ;
} 