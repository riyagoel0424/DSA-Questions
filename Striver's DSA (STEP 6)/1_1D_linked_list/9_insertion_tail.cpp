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

/// FUNCTION TO INSERT TAIL WITH ELEMENT VAL IN LINKED LIST...

node* insert_tail(node*head,int val){

    if(head==NULL){
        return new node(val,head);
    }
    node* temp = head;
    while(temp->next != nullptr){ /// WHILE MEIN CONDITION YE DI TAKI LAST NODE PR RUK JAYE
        temp = temp->next;
    }
    
    if(temp->next == nullptr){
        node* tail = new node(val);  /// EK NEW NODE BNAA DI ORR BSS LAST VALE KA NEXT ISS NODE KO BNA DIA 
        temp->next = tail;
    }
    return head;
}

int main() {

    vector<int> arr = {2 , 4 , 8 , 10};
    
    node* head1 = convert_Arr_to_LL(arr) ;
    
    head1 = insert_tail(head1,5); 
    
    node* temp1 = head1;
    while(temp1){   
        cout<< temp1->data << "  ";     
        temp1 = temp1-> next;    
    }

    return 0;
    
}



