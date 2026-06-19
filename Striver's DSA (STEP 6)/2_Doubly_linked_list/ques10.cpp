#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Employee structure
struct Employee {
    int key;           // Unique 4-digit key
    string name;       // Employee name
    string department; // Employee department
    bool isOccupied;   // Flag to check if the record is occupied
};

// HashTable class
class HashTable {
private:
    vector<Employee> table; // The hash table stored as a vector of Employee records
    int M;                  // Number of memory locations (size of the hash table)

    // Hash function using modulus operator
    int hashFunction(int key) {
        return key % M;
    }

public:
    // Constructor to initialize the hash table with empty employees
    HashTable(int m) : M(m) {
        table.resize(M, {0, "", "", false});
    }

    // Insert an employee record into the hash table
    void insertEmployee(const Employee& emp) {
        int index = hashFunction(emp.key);
        int originalIndex = index; // Save the original index to detect if the table is full

        // Linear probing to handle collisions
        while (table[index].isOccupied) {
            if (table[index].key == emp.key) { // Prevent duplicate entries
                cout << "Error: Employee with key " << emp.key << " already exists." << endl;
                return;
            }
            index = (index + 1) % M; // Move to the next index
            if (index == originalIndex) { // If we loop back to the starting index, table is full
                cout << "Error: Hash table is full. Cannot insert employee with key " << emp.key << endl;
                return;
            }
        }

        // Insert the employee if an empty slot is found
        table[index] = emp;
        table[index].isOccupied = true;
        cout << "Employee with key " << emp.key << " inserted at index " << index << endl;
    }

    // Search for an employee by key
    Employee* searchEmployee(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        // Linear probing to search for the key
        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return &table[index]; // Found the employee
            }
            index = (index + 1) % M;
            if (index == originalIndex) { // Key is not found
                break;
            }
        }

        return nullptr; // Employee not found
    }

    // Display the contents of the hash table
    void displayTable() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < M; i++) {
            if (table[i].isOccupied) {
                cout << "Index " << i << ": Key = " << table[i].key
                     << ", Name = " << table[i].name
                     << ", Department = " << table[i].department << endl;
            } else {
                cout << "Index " << i << ": [Empty]" << endl;
            }
        }
    }
};

// Main function to interact with the user
int main() {
    int M; // Size of the hash table (number of memory locations)
    cout << "Enter the number of memory locations (M): ";
    cin >> M;

    // Create a hash table of size M
    HashTable ht(M);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee emp;
                cout << "Enter employee key (4-digit): ";
                cin >> emp.key;
                cout << "Enter employee name: ";
                cin.ignore(); // Ignore the leftover newline
                getline(cin, emp.name);
                cout << "Enter employee department: ";
                getline(cin, emp.department);
                emp.isOccupied = false; // Initialize as unoccupied

                ht.insertEmployee(emp);
                break;
            }
            case 2: {
                int key;
                cout << "Enter 4-digit key to search for employee: ";
                cin >> key;
                Employee* emp = ht.searchEmployee(key);
                if (emp) {
                    cout << "Employee found: Key = " << emp->key
                         << ", Name = " << emp->name
                         << ", Department = " << emp->department << endl;
                } else {
                    cout << "Employee not found with key " << key << endl;
                }
                break;
            }
            case 3:
                ht.displayTable();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}