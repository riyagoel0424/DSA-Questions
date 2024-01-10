//// OPTIMIZED WAY  ---- >  TIME COMPLEXITY = O(N)
//// ARRAY INPUT KRAKR BUBBLE SORT KR RE

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int ary[] , int n)
{
    for(int i = 0 ; i <= n-2 ; i++)
    {   
        int didswap = 0;
        for(int j =0 ; j <= n-i-1 ; j++)
        {
            if(ary[j] > ary[j+1])
            {
                swap(ary[j] , ary[j+1]);
                didswap = 1 ;
            }
        }
        if(didswap == 0)
        {
            break;             /// AGR UPAR LOOP MEIN KOI SWAPPING NHI HUI MTLB KI ARRAY ALREADY SORT HO CHUKA HAI .. 
                               /// TO AAGE LOOPS CHLAKR NO FAYDA ISLIYE BREAK KRKE BAHR AA GYE 
        }
        cout<<"loop runs " <<endl;    /// YE ISLIYE LIKHA TAAKI DEKH SKE LOOP KITNI BAAR CHLA HAI .. 
    }

}

///////////////////////////////////// UPAR VALA IS BUBBLE SORT KA CODE 

int main(){

    int n ;
    cout << "ENTER THE NUMBER OF ELEMENTS IN THE ARRAY " ;
    cin >> n ;

    int ary[n];

    cout << "WRITE THE ELEMENTS ONE BY ONE "<< endl ;

    for(int i =0 ; i < n ;i++ )
    {
        cin>>ary[i];
    }
    
    bubble_sort(ary , n);

    cout << "THE SORTED ARY CONTAINS " << endl;

    for(int i =0 ; i < n ;i++ )
    {
        cout<< ary[i] << " " ;
    }

    return 0;
}