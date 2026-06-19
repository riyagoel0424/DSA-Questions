/// CONSTRUCTOR (NON PARAMETERISED)

#include<iostream>
#include<string>  
using namespace std;

class Teacher{
private:
    double salary = 80000 ;

public:
    Teacher(){                        //// THIS IS A CONSTRUCTOR (FUNCTION) WITHOUT ANY RETURN TYPE
        cout << "THIS IS A CONSTRUCTOR" << endl;
        dept = "Information Technology" ;   /// USED FOR INITIALISATION OF DATA MEMBERS
    }
    string name;
    string dept;
    string subject;       

};

int main(){

    Teacher T1 ;
    T1.name = "Riya";
    T1.dept = "IT" ;
    T1.subject = "oops" ;

    Teacher T2 ;

    cout << T1.name << endl ;
    cout << T1.dept << endl ;
    cout << T2.dept << endl ;    /// BY DEFAULT ISKA DEPT --> COMPUTER SCIENCE HO GYA BCZ OF CONSTRUCTOR
                                
    return 0;
}