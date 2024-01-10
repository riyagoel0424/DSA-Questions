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
//////////////////////////////////////////////////////////  UPAR VALA IS SELECTION SORT KA CODE 

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
    
    selection_sort(ary , n);

    cout << "THE SORTED ARY CONTAINS " << endl;

    for(int i =0 ; i < n ;i++ )
    {
        cout<< ary[i] << " " ;
    }

    return 0;
}