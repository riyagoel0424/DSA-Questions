/// CONSTRUCTOR (PARAMETERISED)

/// CONSTRUCTOR OVERLOADING WHEN THERE ARE MORE THAN ONE CONSTRUCTOR IN A CLASS
/// (IT IS AN EXAMPLE OF POLYMORPHISM)

#include<iostream>
#include<string>  
using namespace std;

class Teacher{
public:
    string name;
    string dept;
    string subject; 
    double salary; 
    
    /* DONO CONSTRUCTOR MEIN SE DETECT HOGA ACCORDING TO PARAMETERS KI KONSA CONSTRUCTORCALL KRNA HAI */

    Teacher(){                                               /// NON PARAMETERISED
        cout << "THIS IS A CONSTRUCTOR" << endl;
        dept = "Information Technology" ;   
    }

    Teacher(string n , string d , string s , double sal){     /// PARAMETERISED
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    void get_info(){
        cout << "name -- > " << name << endl ;
        cout << "department -- > " << dept << endl ;
        cout << "salary -- > " << salary << endl ;
    }     

};

int main(){

    Teacher T1("Riya" ,"IT","oops" , 20000) ;

    T1.get_info();   

    return 0;
}