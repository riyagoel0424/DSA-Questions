# include <iostream> 
using namespace std;
// MAX 12 TK NUMBERS HO SKTE HAIN IN ARRAY ARR
int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i =0 ; i<n ; i++){
        cin >> arr[i];
    }

    // PRECOMPUTE
    int hash[13] {0};   
    for(int i =0; i < n ; i++){
        hash[arr[i]]++;
    }

    int q ;
    cin >> q; \\ NO. OF ELEMENTS U WANT TO __check_facet

    while(q--){
        int num;
        cin>> num;
        cout<< hash[num];
    }
    return 0;


}