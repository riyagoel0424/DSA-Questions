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

/// FUNCTION TO INSERT NODE BEFORE SOME VALUE IN LINKED LIST WITH ELEMENT VAL

node* insert_before_k(node*head,int k , int val){  /// HERE K IS DATA OF ONE NODE IN LINKED LIST

    if(head==NULL){   /// YE VO CASE HO GYA JBB NULL LINKED LIST HAI ... KHALI LL
        if(k==head->data){
            return new node(val,head);
        }
        else{   /// AGAR EMPTY LINKED LIST MEIN K KI VALUE 2 , 3 AISI KUCH DEDI .. ABB D=SEEDHA 2ND POSITION PR THODI INSERT KRENGE NODE
            return NULL;
        }
    }

    if(k==head->data){
        node* temp = new node(val,head);   /// NEECHE KI 2 LINES KI JGH WRITE HEAD AFTER VAL IN PARAMETERS
        // temp->next = head;
        // head = temp; 
        return temp;  
    }

    node* prev = NULL;
    node* temp = head;
    while(temp){        
        if(k==temp->data){
            node* new_vali_node = new node(val);
            new_vali_node->next = temp;
            prev->next = new_vali_node;
            break;
        }
        prev = temp;
        temp = temp->next;    
    }

    return head;
}

int main() {

    vector<int> arr = {2 , 4 , 8 , 10};
    
    node* head1 = convert_Arr_to_LL(arr) ;
    
    head1 = insert_before_k(head1,4,5); 
    
    node* temp1 = head1;
    while(temp1){   
        cout<< temp1->data << "  ";     
        temp1 = temp1-> next;    
    }

    return 0;
    
}



