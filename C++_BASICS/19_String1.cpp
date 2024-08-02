#include<iostream>
#include<string>     /// HEADER FILE INCLUDED TO USE STRING 
using namespace std;

int main(){
    
    string str1 ;     /// DECLARATION OF A STRING 
    string str2 ;
    string str3 ;

    str1 = "RIYAGOEL" ;                 
    str2 = "RIYA GOEL" ;                /// THIS WILL GIVE RIYA GOEL ... YE STRING KESE BHI LIKHO .. WITH SPACES

    cout<< "WRITE YOUR STRING" << endl ;
    cin >> str3 ;                 //// BUT IF YOU GIVE INPUT "RIYA GOEL" IN TERMINAL ... THEN OUTPUT WILL BE RIYA ONLY 
                                  ////  NO SPACES ARE ACCEPTED AISE

    cout << str1 << endl  ;
    cout << str2 << endl  ;
    cout << str3 << endl  ;

    /// TYPES OF DACLARING A STRING 

    string str4 (5 , 'n');     /// (size , character)  ....... nnnn
    cout << str4 << endl;

    /// METHOD TO GET SPACES IN STRING 

    string str5;
    cout << "WRITE STRING WITH SPACES" << endl;
    getline(cin , str5) ;        /// HUM ABB INPUT MEIN KUCH BHI STRING LIKH SKTE H WITH SPACES
    cout << str5 << endl ;

    return 0;
}