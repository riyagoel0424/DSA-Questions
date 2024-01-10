/// SECOND LARGEST ELEMENT IN A ARRAY (1ST VIDEO KA 2ND CODE )

# include <iostream>
using namespace std;

int sec_largest_num_in_arr(int arr[], int n )
{
    int largest_num = arr[0];                                                 /// LARGEST NUMBER PTA KRA PHLE KI KYA HAI
    for(int i = 1 ; i < n ; i++)
    {
        if( arr[i] > largest_num)
        {
            largest_num = arr[i];
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////
      
    int sec_largest_num = -1;                                                     ///  ABB LARGEST NUMBER KA USE KRKE 
    for(int i = 0 ; i < n ; i++)                                                 /// WE WILL FIND KI SECOND LARGEST NUMBER KYA HAI
    {
        if(arr[i] > sec_largest_num && arr[i]!= largest_num)
        {
            sec_largest_num = arr[i];
        }
    }
    cout << "second largest number of array is "<< sec_largest_num ;
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

    sec_largest_num_in_arr( arr , n );                           /// upar likha function call hua hai

    return 0 ;
} 