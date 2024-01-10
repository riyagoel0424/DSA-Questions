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



///////////////////////////////////// UPAR VALA IS INSERTION SORT KA CODE

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

    insertion_sort(ary , n);

    cout << "THE SORTED ARY CONTAINS " << endl;

    for(int i =0 ; i < n ;i++ )
    {
        cout<< ary[i] << " " ;
    }

    return 0;
}
