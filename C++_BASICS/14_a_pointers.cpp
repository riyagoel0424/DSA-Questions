/// CONCEPT OF POINTERS

/// POINTER ---->  A DATA TYPE (A TYPE OF VARIABLE) WHICH HOLDS THE ADDRESS OF OTHER DATA TYPE

# include <iostream>

using namespace std;

int main(){
    int a = 25 ;

    int* b = &a ;

    ///  & MEANS ADDRESS OF OPERATOR (&a MEANS A KA ADDRESS )

    cout << "THE ADDRESS OF A WHICH IS STORED IN B IS " <<  b << endl ;

    cout << "THE ADDRESS OF A IS " <<  &a << endl ;



    ///  * MEANS DEREFERENCE OPERATOR (VALUE AT THAT ADDRESS)

    cout << "THE VALUE AT ADDRESS B IS " << *b ;




    return 0 ;g


}




