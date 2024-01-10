# include <iostream>

using namespace std;

int main(){
    int age;
    cout << "ENTER YOUR AGE TO CHECK WHETHER YOU ARE ELIGIBLE FOR VOTE OR NOT ";
    cin >> age;

    if (age > 150 || age < 1){                        //  || THIS IS USED AS OR  .... && THIS IS USED AS AND   IN C++
        cout << "shut up , invalid age";
    }
    else if (age >= 18){
        cout << "YOU ARE ELIGIBLE FOR VOTE ";
    }
    else{
        cout << "YOU ARE NOT ELIGIBLE FOR VOTE ";
    }


   /* HUMKO 150+ AGE VALI BAAT KO PHLE LIKHNA HOGA 18+ AGE VALI BBAT SE BCZ AGR
      USER NE 250 AGE DI OR 18+ VALI BAAT PHLE IF MEIN LIKHI HUI TO VO STATEMENT TRUE
      HO JAYEGI AND PRINT HOGA  YOU ARE ELIGIBLE FOR VOTE .. ORR AAGE KI CONDITIONS
      CHECK HI NHI HONGI ..*/

    return 0;

}
