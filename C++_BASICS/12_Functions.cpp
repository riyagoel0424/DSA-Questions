/// CREATE A FUNCTION TO ADD TWO NUMBERS

# include <iostream>

using namespace std;
int sum(int a , int b)
{
    int c;
    c = a + b;
    return c;
}



int main(){
    int a ;
    int b ;
    cout << "ENTER FIRST NUMBER" << endl ;
    cin >> a;
    cout << "ENTER SECOND NUMBER " << endl ;
    cin >> b;
    cout <<  " THE SUM OF TWO NUMBERS IS " << sum(a,b);
    
    return 0 ;
}
