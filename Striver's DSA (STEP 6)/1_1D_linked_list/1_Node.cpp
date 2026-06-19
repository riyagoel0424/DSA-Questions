/// TO CREATE A NODE WHICH IS A SELF REFERENTIAL STRUCTURE


/*THE KEY DIFFERENCE BETWEEN STRUCTURE AND CLASS IS 
STRUCTURE IS COLLECTION OF DATA MEMBERS AND 
CLASS IS COLLECTION DATA MEMBERS AND FUNCTIONS */ 

#include<bits/stdc++.h>
using namespace std;

struct node {    /// NODE IS A SELF DEFINED DATA TYPE

    int data ;
    node* next;

    node (int data1 , node* next1)         /// Constructor
    {   
    data = data1;
    next = next1;
    }

    node (int data1 )         /// Constructor jbb baar baar nullptr naa assign krna ho
    {   
    data = data1;
    next = nullptr;
    }
};


int main() {

    vector<int> v = {2 , 4 , 6 , 8} ;

    node x (v[0] , nullptr);       /// SAME AS WE CALL CONSTRUCTO9R FROM A CLASS
                               /// HERE x IS JUST AN OBJECT OF STRUCTURE node
                            /// IDHR STACK MEIN PHLE X BNAA THEN USKA ADDRESS Y MEIN ALAG SE STORE KIA

    node* y = &x ;             /// Y MEIN HUMNE X OBJECT KA ADDRESS SAVE KIA ... JO JIS DATA TYPE KA HOTA H VHI 
                               /// DATA TYPE KE VARIABLE MEIN USKA ADDRESS SAVE HOTA H

    cout << x.data;


    node* y = new node(v[0] , nullptr) ;   // Node heap mein bani aur uska address direct y mein aa gaya.
    cout << y -> data ;



return 0 ;

    
}



