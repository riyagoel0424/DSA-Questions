# include <iostream>

using namespace std;

int main(){
    int a = 56;
    int b = 3;
    cout << "THE DIVISON OF A AND B INTEGERS IS ALWAYS INTEGER  " << a / b << endl;

    /* 56 / 3   SHOULD BE EQUAL TO 18.66  BUT IN C++  ANY OPERATION DONE BETWEEN ANY TWO INTEGERS
       ALWAYS GIVE ANSWER IN INTEGER ..  SO WE WILL GET ANS AS 18 ... BUT IF WE WANT ANS AS 18.66 IN C++ THEN
       WE HAVE TO DO TYPE CASTING ... WE HAVE TO TYPE CASTE AT LEAST ONE INT IN FLOAT OR DOUBLE   */


    cout << "THE DIVISON OF A AND B AFTER TYPE CASTING IS " << (float)a / b ;


    return 0;

}
