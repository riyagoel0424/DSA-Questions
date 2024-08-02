#include<iostream>
#include<string>     /// HEADER FILE INCLUDED TO USE STRING 
using namespace std;
 
///   BY DEFAULT THE CLASS MEMBERS ARE PRIVATE ... CAN BE USED IN CLASS ONLY
///   WE NEED TO DECLARE THEM IN PUBLIC TO USE THEM OUTSIDE THE CLASS
///   SOMETIMES MEMBERS ARE PROTECTED ... CAN BE USED IN CLASS AND DERIVED CLASS ONLY 
///   CLASS MEMBERS... ATTRIBUTES ...PROPERTIES             /// MEMBER FUNCTIONS .... METHODS                                                          

class Teacher{
private:
    double salary = 80000 ;

public:
    string name;
    string dept;
    string subject;

    void change_dept(string new_dept){
        dept = new_dept;
    }        

};     /// ; SEMICOLON IS NECESSARY AFTER DECLARING CLASS

int main(){

    Teacher T1 ;
    T1.name = "Riya";
    T1.dept = "IT" ;
    T1.subject = "oops" ;

    cout << T1.name << endl ;
    cout << T1.dept << endl ;
    cout << T1.subject << endl ;

    return 0;
}
