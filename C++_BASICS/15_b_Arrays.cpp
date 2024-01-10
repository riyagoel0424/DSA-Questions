/// TO TAKE ELEMENTS OF ARRAY FROM USER AND DISPLAY IT 

# include <iostream>

using namespace std;

int main(){

    int n;
    cout<< "ENTER NUMBER OF ELEMENTS IN ARRAY " ;
    cin >> n ;

    int ary[n];

    cout << "WRITE THE ELEMENTS ONE BY ONE "<< endl ;

    for(int i =0 ; i < n ;i++ )
    {
        cin>>ary[i];
    }

    cout << "THE ARY CONTAINS " << endl;

    for(int i =0 ; i < n ;i++ )
    {
        cout<< ary[i] << " " ;
    }

    return 0;

}
