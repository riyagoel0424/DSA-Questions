///  HOW TO ACCESS PRIVATE MEMBERS OF A CLASS OUTSIDE THE CLASS USING PUBLIC FUNCTIONS

#include<iostream>
using namespace std;

class Teacher{
private:
    double salary1 = 80000 ;
    double salary2;

public:
    double s1 = salary1;     /// agr already upr salary defined h to main mein aise access kr skte h

/// settetr                         /// agr private mein salary initialise h but declare main mein krna h then write a function
    void set_salary(double s2){
        salary2 = s2;
        cout << salary2 << endl;   /// aise bhi print kra skte h salary main mein set krke ya getter function likho
    }

/// getter
    double get_salary(){
        return salary2;
    }

};     /// ; SEMICOLON IS NECESSARY AFTER DECLARING CLASS

int main(){

    Teacher T1 ;
    cout << T1.s1 << endl;

    T1.set_salary(25000);
    // cout << T1.s2;     /// this is not valid ... REASON NEECHE

    cout << T1.get_salary() ;

    return 0;
}


// int a , b;
// a = 5;
// a = b;
// cout << b;    //// THIS GIVES GARBAGE VALUE .... SAME T1.S2 DOES NOT MAKE SENSE