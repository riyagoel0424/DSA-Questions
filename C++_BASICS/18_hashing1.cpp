//// TO COUNT THE NO. OF ELEMENT FROM ARRAY .... [7,4,7,2,6]  HERE 7 EXIST 2 TIMES 

# include <iostream> 
using namespace std;

/*In the context of this program, a hash is an array used to store the count of each element in the input array.
It acts like a dictionary or a map, where each element of the input array is treated as a key,
and its corresponding value is the count of its occurrences.
*/

int main(){

    int n ;
    cin >> n ;

    int arr[n] ;
    for(int i =0 ; i<n ;i++)        /// INPUT OF ARRAY
    {
        cin >> arr[i];
    }

    /// PRECOMPUTE                /// here132 hash is an array
    int hash[13] = {0};           /// JAB ARRAY KE HARR ELEMENT KI VALUE SAME HO ....int arr[3] ={5} ;
    for(int i =0 ; i<n ;i++)
    {
        hash[arr[i]] ++ ;
    }

    int q ;
    cout << "HOW MANY ELEMENTS YOU WANT TO COUNT FROM ARRAY " << endl ;
    cin >> q;

    while(q--)
    {
        int number;
        cin >> number ;
        cout<< hash[number] << endl ;          ///  FETCH 
    }
    return 0;

}