#include<iostream>
#include<string>  
using namespace std;

class Teacher{
private:
    double salary = 80000 ;

public:
    Teacher(){                        
        cout << "THIS IS A CONSTRUCTOR" << endl;
        dept = "Information Technology" ;   
    }

    string dept;  // idhr dept declare baad mein kia h but initialize upr class mein phle kr lia

    /*In C++, the order of member variable declarations in a class does not affect their usage 
    within member functions, including constructors.   (only inn dono ke liye order matter nhi krta in class) */
        
};

int main(){

    Teacher T1 ;
    cout << T1.dept ;
                                
    return 0;
}