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

/// FUNCTION TO DELETE Kth ELEMENT FROM LINKED LIST...

node* delete_k(node*head , int k){

    if (head == NULL) return head;

    node* temp = head;

    if(k==1){
        temp = head;
        head = head->next;
        delete temp;
        return head;    /// IDHR RETURN KR DIA TAKI WHILE LOOP NA CHLE .. VRNA INFINITE HO SKTA H
    }

    int count = 0;
    node* prev = NULL;
    while(temp){  
        count++;      
        if(k==count){
            prev->next = prev->next->next;
            delete temp;
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
    
    head1 = delete_k(head1,3);  
    node* temp1 = head1;

    while(temp1){   
        cout<< temp1->data << "  "; /// TRAVERSE KRKE SBKA DATA PRINT KRA RE EXCEPT DELETED ONE
        temp1 = temp1-> next;   
    }
    return 0;
    
}



