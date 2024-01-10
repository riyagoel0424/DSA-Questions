/// STRING DATA-TYPE
/// IN C++ WE HAVE TO WRITE # include <string> TO USE SOME FUNCTIONS OF STRING IN OUR CODE

# include <iostream>
# include <string>

using namespace std;

int main(){
    string name = "Manya";
    cout << "THE NAME IS " << name << endl ;
    cout << "THE LENGTH IS " << name.length() << endl;
    cout << "THE SUB STRING IS " << name.substr(0,3) << endl ;
    cout << "THE SUB STRING IS " << name.substr(1,8) << endl ;



    /// SUBSTR(a,b) MEIN B INCLUDE NHI HOTA ... a to b-1 index ke char print hote hai
    /// (a,b) a kuch bhi ho skta hai vhi se substring start hoga orr b-1 tk chlega ... agr b ki value length+1 se bdi hai hai to puri string print hogi




    return 0;

}
