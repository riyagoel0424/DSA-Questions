//   PROBLEM 4            DOUBLY LINKED LIST

#include <iostream>
#include <string>
using namespace std;
struct Node {
string aadhar, name, gender, fatherName, motherName, dob;
Node* prev;
Node* next;
};
class DoublyLinkedList {
public:
Node* head;
DoublyLinkedList() : head(nullptr) {}
void insertRecord(string aadhar, string name, string gender, string fatherName, string motherName,
string dob) {
Node* newNode = new Node{aadhar, name, gender, fatherName, motherName, dob, nullptr,
nullptr};
if (!head || head->aadhar >= aadhar) {
newNode->next = head;
if (head) head->prev = newNode;
head = newNode;
return;
}
Node* current = head;
while (current->next && current->next->aadhar < aadhar) {current = current->next;
}
newNode->next = current->next;
if (current->next) current->next->prev = newNode;
current->next = newNode;
newNode->prev = current;
}
void deleteRecord(string aadhar) {
Node* current = head;
while (current) {
if (current->aadhar == aadhar) {
if (current->prev) current->prev->next = current->next;
if (current->next) current->next->prev = current->prev;
if (current == head) head = current->next;
delete current;
cout << "Record with Aadhar " << aadhar << " deleted." << endl;
return;
}
current = current->next;
}
cout << "Record with Aadhar " << aadhar << " not found." << endl;
}
void updateRecord(string aadhar, string name) {
Node* current = head;
while (current) {
if (current->aadhar == aadhar) {
current->name = name;cout << "Record with Aadhar " << aadhar << " updated." << endl;
return;
}
current = current->next;
}
cout << "Record with Aadhar " << aadhar << " not found." << endl;
}
void generateReport(string aadhar) {
Node* current = head;
while (current) {
if (current->aadhar == aadhar) {
cout << "Complete Report:" << endl;
cout << "Aadhar: " << current->aadhar << endl;
cout << "Name: " << current->name << endl;
cout << "Gender: " << current->gender << endl;
cout << "Father's Name: " << current->fatherName << endl;
cout << "Mother's Name: " << current->motherName << endl;
cout << "Date of Birth: " << current->dob << endl;
return;
}
current = current->next;
}
cout << "Record not found." << endl;
}
};
int main() {
DoublyLinkedList db;string aadhar, name, gender, fatherName, motherName, dob;
while (true) {
cout << "1. Insert Record\n2. Delete Record\n3. Update Record\n4. Generate Report\n5.Exit\nChoose an opƟon: ";
int choice;
cin >> choice;
switch (choice) {
case 1:
cout << "Enter Aadhar, Name, Gender, Father's Name, Mother's Name, Date of Birth: ";
cin >> aadhar >> name >> gender >> fatherName >> motherName >> dob;
db.insertRecord(aadhar, name, gender, fatherName, motherName, dob);
break;
case 2:
cout << "Enter Aadhar to delete: ";
cin >> aadhar;
db.deleteRecord(aadhar);
break;
case 3:
cout << "Enter Aadhar and new Name to update: ";
cin >> aadhar >> name;
db.updateRecord(aadhar, name);
break;
case 4:
cout << "Enter Aadhar to generate report: ";
cin >> aadhar;
db.generateReport(aadhar);
break;case 5:
return 0;
default:
cout << "Invalid opƟon. Try again." << endl;
}
}
}