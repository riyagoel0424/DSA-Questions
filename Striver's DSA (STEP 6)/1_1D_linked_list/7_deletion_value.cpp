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

/// FUNCTION TO DELETE ELEMENT WITH VALUE [K] FROM LINKED LIST...  
/// BSS PHLE COUNT USE KIA THA BUT ABB DIRECT TEMP->DATA DEKH KR CHECK KR RE HAI 

node* delete_node_with_value_el(node*head , int el){

    if (head == NULL) return head;

    node* temp = head;

    if(head->data == el){
        temp = head;
        head = head->next;
        delete temp;
        return head;    /// IDHR RETURN KR DIA TAKI WHILE LOOP NA CHLE .. VRNA INFINITE HO SKTA H
    }

    node* prev = NULL;
    while(temp){      
        if(temp->data == el){
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
    
    head1 = delete_node_with_value_el(head1,3);  
    node* temp1 = head1;

    while(temp1){   
        cout<< temp1->data << "  "; /// TRAVERSE KRKE SBKA DATA PRINT KRA RE EXCEPT DELETED ONE
        temp1 = temp1-> next;   
    }
    return 0;
    
}



