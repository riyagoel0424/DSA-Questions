/// VECTOR IS NOTHING BUT A DYNAMIC ARRAY ..... MEMORY IS NOT PREDEFINED IN VECTORS

# include <iostream>
# include <vector>        ///// WE HAVE TO INCLUDE THIS HEADER FILE TO USE VECTOR 
using namespace std;

int main(){
    vector<int> v;
    
    v.push_back(1);  /// TO ADD ELEMENT IN A VECTOR 
    v.push_back(2);
    v.push_back(3);

    /// THERE ARE THREE WAYS TO TRAVERSE IN A VECTOR

    for(int i =0 ; i<v.size() ; i++)
    {
        cout << v[i] << endl;
    }


    vector<int> :: iterator it;
    for(it = v.begin() ; it!= v.end() ; it++)
    {
        cout<< *it << endl;   /// BECAUSE ITERATOR IS A POINTER
    }
 

    for(auto element:v)
    {
        cout << element << endl;
    }

    v.pop_back();

    vector<int> v2 (3,50);      ///  WE CAN DEFINE SIZE OF VECTOR AND SATH MEIN HI ELEMENT
    /// HERE V2 = 50 50 50

    ///  vector<int> v3 (4 , 51 , 52 , 53 , 54);    /// THIS IS WRONG , YOU CANT WRITE THIS


    /// SOME FUNCTIONS ARE -

    swap(v,v2);

    for(auto element:v)
    {
        cout << element << endl;
    }

    for(auto element:v2)
    {
        cout << element << endl;
    }

    ///  sort(v.begin(),v.end());    /// i dont know ye kyu ni chl ra
    


    return 0;


}