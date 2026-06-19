#include <iostream>
#include <string>
using namespace std;

struct Address {
    string houseNo, street, city, state, country;
};

struct Student {
    int rollNo;
    string name, fatherName, motherName, studentClass, semester, branch;
    Address address;
};

const int MAX = 100;  // Maximum number of records
Student students[MAX];
int recordCount = 0;

void addRecord() {
    if (recordCount < MAX) {
        Student &s = students[recordCount++];
        cout << "Enter Roll No: "; cin >> s.rollNo;
        cout << "Enter Name: "; cin.ignore(); getline(cin, s.name);
        cout << "Enter Father's Name: "; getline(cin, s.fatherName);
        cout << "Enter Mother's Name: "; getline(cin, s.motherName);
        cout << "Enter Class: "; getline(cin, s.studentClass);
        cout << "Enter Semester: "; getline(cin, s.semester);
        cout << "Enter Branch: "; getline(cin, s.branch);
        cout << "Enter Address (House No, Street, City, State, Country): ";
        getline(cin, s.address.houseNo); getline(cin, s.address.street); getline(cin, s.address.city);
        getline(cin, s.address.state); getline(cin, s.address.country);
    } else {
        cout << "Record limit reached!\n";
    }
}

void searchByCity(string city) {
    for (int i = 0; i < recordCount; ++i) {
        if (students[i].address.city == city) {
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << "\n";
        }
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add Record\n2. Search by City\n0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addRecord();
        else if (choice == 2) {
            string city;
            cout << "Enter City: "; cin.ignore(); getline(cin, city);
            searchByCity(city);
        }
    } while (choice != 0);
    
    return 0;
}
