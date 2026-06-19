#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

// DECLARATION OF NODE
struct record {
    int aadhar_no[3];
    char name_of_person[100];
    char gender[10];
    char father_name[100];
    char mother_name[100];
    char date_of_birth[30];
};

struct node {
    struct record rd;
    struct node *prev;
    struct node *next;
};

typedef struct node nd;
nd *head = NULL;
nd *tail = NULL;

// Function to handle string input for employee names, etc.
char *character(char *str) {
    char ch;
    int i = 0;
    do {
        ch = getchar();
        if (isalpha(ch) || ch == ' ' || ch == '.') {
            str[i++] = ch;
        }
    } while (ch != '\n' && ch != '\r');
    str[i] = '\0';
    return str;
}


void report(){
    FILE *fp;
    fp=fopen("record4.txt","w");
    if(fp==NULL){
        cout<<"ERROR IN OPENING THE FILE\n";
        
    }
    if(head!=NULL){
        fwrite(head,sizeof(nd),1,fp);
    
    }
    
    fclose(fp);
    return;
}

// Function to input the date of birth
void date_of_birth(char *date) {
    int dd, mm, yy;
    cout << "\nENTER THE DATE ONLY\n";
    cin >> dd;
    cout << "ENTER THE MONTH ONLY\n";
    cin >> mm;
    cout << "ENTER THE YEAR ONLY\n";
    cin >> yy;
    if ((dd > 0 && dd <= 31) && (mm > 0 && mm <= 12) && (yy > 1900 && yy <= 2024)) {
        // Check for leap year and valid date
        bool leap = (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0));
        if (mm == 2) {
            if ((leap && dd > 29) || (!leap && dd > 28)) {
                cout << "INVALID DATE FOR FEBRUARY\n";
                date_of_birth(date);
                return;
            }
        } else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) {
            cout << "INVALID DATE FOR THE MONTH\n";
           date_of_birth(date);
            return;
        } else if (dd > 31) {
            cout << "INVALID DATE\n";
            date_of_birth(date);
            return;
        }

        sprintf(date, "%02d-%02d-%04d", dd, mm, yy);
    } else {
        cout << "INVALID DATE\n";
        date_of_birth(date);
    }
}

void addhar_num(int *aadhar) {
    int ff, mm, ll;

    cout << "ENTER THE FIRST FOUR DIGITS OF AADHAR CARD\n";
    cin >> ff;
    if (ff < 1000 || ff > 9999) {  // Valid range for four digits is 1000-9999
        cout << "INVALID\n";
       addhar_num(aadhar);
        return;
    }
    aadhar[0] = ff;

    cout << "ENTER THE MIDDLE FOUR DIGITS OF AADHAR CARD\n";
    cin >> mm;
    if (mm < 1000 || mm > 9999) {  // Valid range for four digits is 1000-9999
        cout << "INVALID\n";
       addhar_num(aadhar);
        return;
    }
    aadhar[1] = mm;

    cout << "ENTER THE LAST FOUR DIGITS OF AADHAR CARD\n";
    cin >> ll;
    if (ll < 1000 || ll > 9999) {  // Valid range for four digits is 1000-9999
        cout << "INVALID\n";
        addhar_num(aadhar);
        return;
    }
    aadhar[2] = ll;
}

void input_rec(nd* newnode, int aadhar_num[3]) {
    cout << "ENTER THE DATA\n";
    cout << "AADHAR NUMBER: ";
    for (int i = 0; i < 3; i++) {
        newnode->rd.aadhar_no[i] = aadhar_num[i];
    }
    cout << "ENTER THE NAME OF PERSON\n";
    character(newnode->rd.name_of_person);
    cout << "ENTER THE FATHER'S NAME\n";
    character(newnode->rd.father_name);
    cout << "ENTER THE MOTHER'S NAME\n";
    character(newnode->rd.mother_name);
    cout << "ENTER THE GENDER OF THE PERSON\n";
    character(newnode->rd.gender);
    cout << "ENTER THE DATE OF BIRTH\n";
    date_of_birth(newnode->rd.date_of_birth);
}
void insert() {
    nd* ptr = head;
    nd* newnode = (nd*)malloc(sizeof(nd));
    newnode->next = NULL;
    newnode->prev = NULL;
    int addhar[3];
     addhar_num(addhar);
    input_rec(newnode,addhar);

    if (ptr == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        while (ptr != NULL) {
            if (memcmp(ptr->rd.aadhar_no, newnode->rd.aadhar_no, sizeof(newnode->rd.aadhar_no)) == 0) {
                cout << "DUPLICACY IS THERE\n";
                free(newnode);
                return;
            }
            ptr = ptr->next;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    //log_record(newnode, "New Record Inserted:");
}

void delete_record(int *aadhar_num) {
    nd* ptr = head;

    if (ptr == NULL) {
        cout << "LIST IS EMPTY\n";
        return;
    }

    while (ptr != NULL) {
        if (memcmp(ptr->rd.aadhar_no, aadhar_num, 3 * sizeof(int)) == 0) {
            if (ptr == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else if (ptr == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }

            //log_record(ptr, "Record Deleted:");
            free(ptr);
            return;
        }
        ptr = ptr->next;
    }

    cout << "RECORD NOT FOUND\n";
}

void update_record(int *aadhar_num) {
    nd* ptr = head;
    int addhar[3];

    if (ptr == NULL) {
        cout << "LIST IS EMPTY\n";
        return;
    }

    while (ptr != NULL) {
        if (memcmp(ptr->rd.aadhar_no, aadhar_num, 3 * sizeof(int)) == 0) {
            addhar_num(addhar);
            input_rec(ptr, addhar);
            //log_record(ptr, "Record Updated:");
            return;
        }
        ptr = ptr->next;
    }

    cout << "RECORD IS NOT THERE FOR UPDATE\n";
}

void search_rec(int *aadhar_num) {
    nd* ptr = head;

    if (ptr == NULL) {
        cout << "LIST IS EMPTY\n";
        return;
    }

    while (ptr != NULL) {
        if (memcmp(ptr->rd.aadhar_no, aadhar_num, 3 * sizeof(int)) == 0) {
            cout << "Record Found:\n";
            cout << "Aadhar Number: "
                 << setw(4) << setfill('-') << ptr->rd.aadhar_no[0] << "-"
                 << setw(4) << setfill('-') << ptr->rd.aadhar_no[1] << "-"
                 << setw(4) << setfill('-') << ptr->rd.aadhar_no[2] << endl;
            cout << "Name: " << ptr->rd.name_of_person << endl;
            cout << "Gender: " << ptr->rd.gender << endl;
            cout << "Father's Name: " << ptr->rd.father_name << endl;
            cout << "Mother's Name: " << ptr->rd.mother_name << endl;
            cout << "Date of Birth: " << ptr->rd.date_of_birth << endl;
            return;
        }
        ptr = ptr->next;
    }

    cout << "RECORD IS NOT THERE FOR SEARCH\n";
}

void display() {
    nd* ptr = head;

    if (ptr == NULL) {
        cout << "IT IS EMPTY NO RECORD FOUND\n";
        return;
    }

    while (ptr != NULL) {
        cout << "---------------------------------------" << endl;
        cout << "Aadhar Number: "
             << setw(4) << setfill('0') << ptr->rd.aadhar_no[0] << "-"
             << setw(4) << setfill('0') << ptr->rd.aadhar_no[1] << "-"
             << setw(4) << setfill('0') << ptr->rd.aadhar_no[2] << endl;
        cout << "Name: " << ptr->rd.name_of_person << endl;
        cout << "Gender: " << ptr->rd.gender << endl;
        cout << "Father's Name: " << ptr->rd.father_name << endl;
        cout << "Mother's Name: " << ptr->rd.mother_name << endl;
        cout << "Date of Birth: " << ptr->rd.date_of_birth << endl;
        ptr = ptr->next;
    }
}

int main() {
    int i;
    int aadhar_num[3];
    while (true) {
        cout << "1. INSERT \n2. DELETE \n3. FIND  \n4. UPDATE \n5. DISPLAY\n6. EXIT\n";
        cout << "ENTER THE CHOICE\n";
        cin >> i;
        switch (i) {
            case 1:
                insert();
                break;
            case 2:
                cout << "ENTER THE AADHAR NUM TO BE DELETED\n";
                addhar_num(aadhar_num);
                delete_record(aadhar_num);
                break;
            case 3:
                cout << "ENTER THE AADHAR NUM TO BE SEARCHED\n";
                addhar_num(aadhar_num);
                search_rec(aadhar_num);
                break;
            case 4:
                cout << "ENTER THE AADHAR NUM TO BE UPDATED\n";
                addhar_num(aadhar_num);
                update_record(aadhar_num);
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "EXITING\n";
                return 0;
            default:
                cout << "ENTER ANOTHER CHOICE\n";
                break;
        }
    }
    report();
    return 0;
}