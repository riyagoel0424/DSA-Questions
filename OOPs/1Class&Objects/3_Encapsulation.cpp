/// ENCAPSULATION
/// WRAPPING UP OF "DATA AND MEMBER FUNCTIONS" IN A SINGLE UNIT CALLED CLASS
/// THROUGH ENCAPSULATION .... WE CAN DO "DATA HIDING" BY MAKING DATA PRIVATE OR PROTECTED  IN CLASS 
/// JESE BANK ACCOUNT MEIN PASSWORD OR BALANCE KO PRIVATE RKHNA IS DATA HIDING

#include<iostream>
using namespace std;

class Acount{           /// ENCAPSULATION
private:
    double balance;
    string password;     /// DATA HIDING 

public:
    string username;
    string account_id;

    void get_username(){
        cout << username ;
    }

};

