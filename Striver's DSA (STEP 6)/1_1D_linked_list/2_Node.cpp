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

//// FUNCTION TO CONVERT ARRAY TO LINKED LIST
/// IN THIS WE JUST NEED TO RETURN VALUE OF HEAD 
/// RETURN VALUE DATA TYPE ... FUNCTION NAME ... ATTRIBUTES

node* convert_Arr_to_LL(vector<int> &arr){   
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size() ;i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
/// YE TEMP MOVER HEAD SBB USE KRKE LINKED LIST BNAYI HAI BSS .. NEECHE INT MAIN MEIN KOI USE NHI HAI


int main() {

    vector<int> arr = {2 , 4 , 8 , 10};
    
    node* head1 = convert_Arr_to_LL(arr) ;
    // FUNCTION MEIN RETURN HEAD MEANS ADDRESS OF 1ST DABBA RETURN KREGA 
    // USS DABBE KA DATA PRINT KRANE KE LIYE PHLE HEAD1 POINTER MEIN HEAD VALA ADDRESS STORE KIA

    cout << head1->data;

    return 0;

    
}



