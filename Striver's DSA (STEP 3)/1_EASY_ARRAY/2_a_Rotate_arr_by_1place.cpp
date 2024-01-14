/// LEFT ROTATE AN ARRAY BY D PLACES (2ND VIDEO KA 1ST CODE)

#include<iostream>    
using namespace std;

void rotation(int arr[], int n , int D)
{   
    if(D % n == 0)      /// IF D IS MULTIPLE OF N OR N THEN ARAAY GHOOM KR VHI AA JAYEGA
    {
        cout<<"ARRAY WILL REMAIN SAME";
    }
    else
    {   
        D = D % n;    /// N BAAR ROTATE KRKE WE WILL GET SAME ARRAY

        int temp[D];   /// TEMP ARRAY MEIN FIRST D ELEMENTS STORE KRA LENGE 
        for(int i = 0 ;i < D ; i++)
        {
            temp[i] = arr[i];
        }

        for(int i = D ; i < n ; i++)   /// FRR D KE BAAD VALE SAARE ELEMENTS KO AAGE LE AAYEGE
        {
            arr[i-D] = arr[i];
        }
        
        for(int i = 0; i < D; i++)    /// FRR D KE BAAD VALE ELEMENTS AAGE LAANE KE BAAD USKE PEECHE TEMP VALA ARRAY JOD DENGE
        {
            arr[n-D+i] = temp[i];
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

    int D;
    cout<<"Enter the value of D " << endl;
    cin >> D;

    rotation(arr, n , D);

    cout<< "Rotated array is ";

    for(int i =0 ; i < n ;i++ )
    {
        cout<< arr[i] << " " ;
    }                                                   
    
    return 0 ;
} 
