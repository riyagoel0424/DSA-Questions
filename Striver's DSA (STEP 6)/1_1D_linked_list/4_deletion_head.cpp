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

    node (int data1 )         
    {   
    data = data1;
    next = nullptr;
    }
};

//// FUNCTION TO CONVERT ARRAY TO LINKED LIST
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

/// FUNCTION TO DELETE HEAD FROM LINKED LIST...

node* delete_head(node*head){

    if (head == NULL) return head;
    
    node* temp = head;
    head = head->next;
    delete temp;      /// or free(temp)
    return head;
}

int main() {

    vector<int> arr = {2 , 4 , 8 , 10};
    
    node* head1 = convert_Arr_to_LL(arr) ;
    
    head1 = delete_head(head1);  /// phle sirf delete_head(head1); likha tha chla nhi ... 2 hi de ra tha output
    //// then head1 = delete_head(head1); likha bcz head1 mein toh change hua hi nhi 
    cout<< head1->data;

    return 0;
    
}



