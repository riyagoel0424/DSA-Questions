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

/// FUNCTION TO INSERT HEAD WITH ELEMENT VAL IN LINKED LIST...

node* insert_head(node*head,int val){
    
    node* temp = new node(val);
    temp->next = head;
    head = temp;   /// PHLE temp = head LIKHA THA WHICH WAS WRONG KYUNKI TEMP 2ND POSITION PR CHLA GYA BUT LAANA HEAD KO 1ST POSITION PR HAI
    return head;
}

int main() {

    vector<int> arr = {2 , 4 , 8 , 10};
    
    node* head1 = convert_Arr_to_LL(arr) ;
    
    head1 = insert_head(head1,5); 
    
    node* temp1 = head1;
    while(temp1){   
        cout<< temp1->data << "  ";     
        temp1 = temp1-> next;    
    }

    return 0;
    
}



