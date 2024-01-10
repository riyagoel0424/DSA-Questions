/// CONCEPT OF POINTER TO POINTER
/// POINTER TO POINTER ---- > EK AISA VARIABLE JO POINTER KE ADDRESS KO STORE KRE

# include <iostream>

using namespace std;

int main(){
    int a = 25 ;

    int* b = &a ;       /// b IS A POINTER VARIABLE

    int** c = &b ;      /// c IS A POINTER TO POINTER VARIABLE


    cout << "THE VALUE OF A NUMBER IS " << a <<endl;
    cout << "THE ADDRESS OF THAT NUMBER IN MEMORY IS " << &a << endl ;                        /// ye vali line
    cout << "THE ADDRESS OF THAT NUMBER IN MEMORY WHICH IS STORED IN B IS " << b << endl ;    /// or ye vali line ka mtlb same hai ki a ka address(b = &a)
    cout << "THE VALUE AT THE ADDRESS STORED IN B IS " << *b << endl;
    cout << "THE ADDRESS OF B STORED IN C IS " << c << endl ;
    cout << "THE VALUE AT THE ADDRESS STORED IN C IS " << *c << endl ;
    cout << "THE VALUE AT THE ADDRESS STORED IN B IS " << **c ;

    return 0;
}
