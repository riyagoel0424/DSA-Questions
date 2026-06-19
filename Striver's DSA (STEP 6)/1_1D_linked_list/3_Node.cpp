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

int main() {

    vector<int> arr = {2 , 4 , 8 , 10};
    
    node* head1 = convert_Arr_to_LL(arr) ;
    
    /// TRAVERSAL IN LINKED LIST

    node* temp1 = head1;
    while(temp1){   /// MEANS TEMP != NULLPTR
        cout<< temp1->data << "  ";     /// TRAVERSE KRKE SBKA DATA PRINT KRA RE
        temp1 = temp1-> next;    /// BASICALLY TEMP++ MEANS TEMP PHLE HEAD THA ABB NEXT DABBE PR JANA HAI AND USKA ADDRESS NEXT MEIN HAI
    }

    return 0;
 /// TEMP1 , HEAD1 ISLIYE LIKHA BCZ FUNCTION VALE HEAD OR TEMP FUNCTION KE HAI IDHR SE KOI LENA DENA NHI HAI 
 /// VRNA ISDHR BHI TEMP HEAD LIKH SKTE THE DOBARA SE
    
}



