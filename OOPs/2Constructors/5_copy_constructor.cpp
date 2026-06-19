// COPY CONSTRUCTOR

// A SPECIAL CONSTRUCTOR USED TO CREATE A NEW OBJECT AS A COPY OF AN EXISTING OBJECT
// (SPECIAL CONSTRUCTOR USED TO COPY PROPERTIES OF ONE OBJECT INTO ANOTHER)

#include<iostream>
#include<string>  
using namespace std;

class Teacher{
public:
    string name;
    string dept;
    string subject; 
    double salary; 

    Teacher(string n , string d , string s , double sal){     /// PARAMETERISED
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    Teacher(Teacher &obj){
        cout << "HEY I AM A COPY CONSTRUCTOR " << endl;
        name = obj.name;
        dept = obj.dept;
        subject = obj.subject;
        salary = obj.salary;

    }

    void get_info(){
        cout << "name -- > " << name << endl ;
        cout << "department -- > " << dept << endl ;
        cout << "salary -- > " << salary << endl ;
    }     

};

int main(){

    Teacher T1("Riya" ,"IT","oops" , 20000) ;

    Teacher T2(T1);
    T2.get_info();  
    
/* AGR HUM COPY CONSTRUCTOR NA BNATE ... OR T2 MEIN T1 PAAS KRTE
 TO BY DEFAULT COPY CONSTRUCTOR BAAN JATA*/ 

    return 0;
}

