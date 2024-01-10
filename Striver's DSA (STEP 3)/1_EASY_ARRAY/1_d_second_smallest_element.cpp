/// SECOND SMALLEST ELEMENT IN A ARRAY 

# include <iostream>
using namespace std;

int sec_smallest_num_in_arr(int arr[], int n )
{
        int largest = arr[0];
    for(int i = 1 ; i < n ; i++)
    {
        if( arr[i] > largest)
        {
            largest = arr[i];
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////

    int smallest_num = arr[0];                                                 /// LARGEST NUMBER PTA KRA PHLE KI KYA HAI
    for(int i = 1 ; i < n ; i++)
    {
        if( arr[i] < smallest_num)
        {
            smallest_num = arr[i];
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////
      
    int sec_smallest_num = largest;                                                     ///  ABB LARGEST NUMBER KA USE KRKE 
    for(int i = 0 ; i < n ; i++)                                                 /// WE WILL FIND KI SECOND LARGEST NUMBER KYA HAI
    {
        if(arr[i] < sec_smallest_num && arr[i]!= smallest_num)
        {
            sec_smallest_num = arr[i];
        }
    }
    cout << "second smallest number of array is "<< sec_smallest_num ;
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
    }                                                            /// int main se yha tk just array input kraya hai

    sec_smallest_num_in_arr( arr , n );                           /// upar likha function call hua hai

    return 0 ;
} 