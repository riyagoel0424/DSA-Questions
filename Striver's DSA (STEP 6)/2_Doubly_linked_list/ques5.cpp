[4:49 pm, 18/11/2024] +91 77104 47055: #include <iostream>
using namespace std;


// Function to push an item onto the stack
int push(int stack[], int &TOS, int info, int n) {
    if (TOS== n) {
        cout << "Overflow" << endl;
        return TOS;
    }
    TOS = TOS + 1;
    stack[TOS] = info;
    return TOS;
}

// Function to pop an item from the stack
int POP(int stack[], int &TOS) {
    if (TOS==0) {
        cout << "Underflow" << endl;
        return 0;
    }
    int info = stack[TOS];
    TOS = TOS - 1;
    return info;
}

void traverse(int stack[], int &TOS, int SIZE) {
    int BS[SIZE];  // Back Stack
    int TOSB = 0; // Top of Back Stack

    while (TOS!=0) {
        int info = POP(stack, TOS);
        push(BS, TOSB, info, SIZE);
    }

    // Reconstruct the original stack
    while…
[4:49 pm, 18/11/2024] +91 77104 47055: #include <iostream>
using namespace std;
#define SIZE 10

void traverse(int queue[], int& front, int& rear) {
    int item;
    //initializing backup queue

    int BackupQueue[SIZE];   
    int BackupFront = 0;  
    int BackupRear = 0; 

    // Check for empty queue
    if (front==0 && rear==0) {
            cout<<"Queue is empty"<<endl;
        return;
    }
    // Backup the original queue into the backup queue
    BackupFront=BackupFront+1;
    while (front <= rear) {
        item=queue[front];
        front=front+1;
        BackupRear=BackupRear+1;
        BackupQueue[BackupRear] = item;
    }
    // Restore the original queue from the backup queue
     rear=0;
     front=front+1;
     while(BackupFront<BackupRear)
   {
    rear=rear+1;
    item=BackupQueue[BackupFront];
    queue[rear]=item;
    BackupFront=BackupFront+1;

   }
}
int     Delete( int queue[], int& front, int& rear, int item) {
        if (front > rear) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        if (queue[front] == item) {
            front++;
            cout<<"item deleted ";
            return 1;
        }
        cout<<"item cant be deleted"<<item;
        return 0;
    }
 

void insert(int queue[], int& front, int& rear, int Size, int item) {
    if (rear == Size) {
        cout << "Queue is full. Cannot insert." << endl;
        return;
    }
else{
    queue[rear] = item;
    cout<<"item inserted in the queue:";
    cout << queue[rear] << endl;
    rear++;
}
}

int main() {
   
    int queue[SIZE];
    int front=0;
    int rear=0;
   
    
    traverse(queue, front, rear);

    insert(queue, front, rear,SIZE, 23);
    insert(queue, front, rear,SIZE, 25);
    insert(queue, front, rear,SIZE, 29);
  
   
    Delete(queue, front , rear, 23);

    traverse(queue, front, rear);

    return 0;
}