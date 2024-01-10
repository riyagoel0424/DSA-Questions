# include <iostream>

using namespace std;

// SWITCH STATEMENTS
// THESE ARE BASICALLY USED TO PERFORM SOMETHING FOR SOME SPECIAL CASES FOR A VARIABLE

int main(){
    int age;
    cout << "ENTER YOUR AGE ";
    cin >> age;

    switch(age)                           // SWITCH MEIN HUMNE JO BHI VARIABLE LIA ABB HUM USKE ALAG ALAG CASES KE LIYE KUCH KRENGE
    {                                     // JESE AGE MEIN 18 ,1 ,60 KE LIYE KUCH PRINT KRAYA ORR BAAKI AGES DEFAULT MEIN AA GYI
    case 18:                              // BREAK KRNA BHOT ZROORI HAI VRNA SBB KUCH PRINT HO JAYEGA
        cout << "YOU ARE AN ADULT ";
        break;

    case 1:
        cout << "YOU ARE A KID ";
        break;

    case 60:
        cout << "YOU ARE OLD ";
        break;

    default:
        cout << "NO SPECIAL CASE ";
        break;
    }

    return 0;
}
