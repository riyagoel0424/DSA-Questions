/// SMALLEST ELEMENT IN A ARRAY 

# include <iostream>
using namespace std;

void smallest_num_in_arr(int arr[], int n )
{
    int smallest = arr[0];
    for(int i = 1 ; i < n ; i++)
    {
        if( arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    cout << "The smallest number in array is " << smallest;
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
    smallest_num_in_arr( arr,  n );                              /// upar likha function call hua hai
    
    return 0 ;
} 