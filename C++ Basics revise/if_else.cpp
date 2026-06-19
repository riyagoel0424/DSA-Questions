# include <iostream>
using namespace std;

int main(){

    int age ;
    cin >> age ;

    if (age > 150 || age < 1){
        cout << "you can vote " << endl;
    }

    else if (age >= 18) {
        cout << "invalid age " << endl;
    }

    else {
        cout<< "you cannot vote ";
    }
    
    return 0;
}