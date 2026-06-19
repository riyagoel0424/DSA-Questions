/////  PROBLEM 6          SELECTION BUBBLE INSETION SORTING

//// WORST OR AVERAGE TIME COMPLEXITY = O(N^2)
//// ARRAY INPUT KRAKR SELECTION SORT KR RE

#include<bits/stdc++.h>      
using namespace std;

void selection_sort(int ary[] ,int n)
{
    for(int i = 0 ; i <= n-2 ; i++)  // yha i < n-1 bhi likh skti thi agr equal to nhi daalti to  
    /// UPAR N-2 TAK CHLE BCZ AGR SAARE SECOND LAST INDEX TK KE ELEMENTS SORT HO GYE TO LAST ELEMENT TO APNE AAP SORTED HOGA NA 
    {

        for (int j = i+1 ; j <= n-1 ; j++)             /// agr j = i lete to bhi chal jata bcz vo no. khud se compare hoga 
        {
            if( ary[j] < ary[i])
            {
                swap(ary[j] , ary[i]);
            }
        }
        
    }

}

//// WORST OR AVERAGE TIME COMPLEXITY = O(N^2)
//// ARRAY INPUT KRAKR BUBBLE SORT KR RE  


void bubble_sort(int ary[] , int n)
{
    for(int i = 0 ; i <= n-1 ; i++)
    {
        for(int j =0 ; j <= n-i-1 ; j++)
        {
            if(ary[j] > ary[j+1])
            {
                swap(ary[j] , ary[j+1]);
            }
        }
    }

}

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

//// WORST OR AVERAGE TIME COMPLEXITY = O(N^2)
//// ARRAY INPUT KRAKR INSERTION SORT KR RE

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int ary[] , int n )
{
    for(int i = 0 ; i <= n-1 ; i++)                    /// i = 1 se bhi start kr skte hai bcz i = 0 pr only 1st element ka array hoga jo ofcourse sorted hai
    {
        int j = i;
        while( j > 0 && ary[j-1] > ary[j])
        {
            swap(ary[j-1] , ary[j]);

            j--;

            cout<< "LOOP RUNS ";   /// TO CHECK AGR SORTED ARRAY DENGE TBB BHI LOOP KITNI BAAR CHLEEGA
        }
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