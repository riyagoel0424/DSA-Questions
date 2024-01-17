/// UNION OF TWO ARRAYS     /// THIS WILL ALSO BE SORTED 

#include<bits/stdc++.h>    
using namespace std;

void union_array(int arr1[] , int arr2[] , int n1 , int n2)
{
    set<int>st;                                    /// DECLARING A SET
    
    for(int i =0 ; i< n1 ; i++)                   /// INSERTING THE ELEMENTS OF FIRST ARRAY IN SET
    {
        st.insert(arr1[i]);
    }

    for(int i =0 ; i< n2 ; i++)                   /// INSERTING THE ELEMENTS OF SECOND ARRAY IN SET 
    {
        st.insert(arr2[i]);
    }

    int Union[st.size()];               /// st NAMAK SET MEIN SE ELEMENTS UNION ARRAY MEIN BHEJNA OR PRINT KRANA
    int i = 0;
    for(auto it : st)
    {
        cout << it << " ";
    }
}

int main(){
    /// FIRST INPUT TWO ARRAYS FROM THE USER  ... INN DONO ARRAYS KA UNION CHAHIYE
    int n1 ,n2;

    cout << "The number of elements in 1st array " << endl ;    /// FIRST ARRAY
    cin >> n1 ;
    int arr1[n1];
    cout << "Now write the elements of 1st array " <<endl ;
    for(int i = 0 ; i < n1 ;i++)
    {
        cin >> arr1[i] ;
    }      

    cout << "The number of elements in 2nd array " << endl ;   /// SECOND ARRAY 
    cin >> n2 ;
    int arr2[n2];
    cout << "Now write the elements 2nd array " <<endl ;
    for(int i = 0 ; i < n2 ;i++)
    {
        cin >> arr2[i] ;
    } 

    union_array(arr1 , arr2, n1 , n2);
                                                
    return 0 ;
}