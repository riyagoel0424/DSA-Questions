# include <iostream>

using namespace std;

int main(){
    float a = 23.6;
    a = 46.9;

    /*AISE A KI VALUE HUMNE CHANGE KR DI PR AGR KOI VARIABLE HAI JISKI 
      VALUE THROUGHOUT CODE HUM CHANGE NI KRNA CHAHTE THEN USE A KEYWORD 
      CONST VARIABLE SE PHLE ..... OR FRR TUMNE AGR USS VARIABLE KO 
      CHANGE KRNA CHAAAH THEN IT WILL GIVE YOU AN ERROR

    */ 

    int const b = 65;
    // b = 25;   this will give you an error


    cout<< a << endl << b; 
 

    return 0;
}