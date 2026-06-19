///  this POINTER

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

};

int main(){

    Teacher T1("Riya" ,"IT","oops" , 20000) ;  

    return 0;
}