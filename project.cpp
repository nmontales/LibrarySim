#include "project.h"
#include <iostream>
using namespace std;

//----------------Book---------------------
Book::Book() : code(0), title(""), available(0), rented(0) {}
Book::Book(int c, string t, int a, int r, int age, string pub, int pubd)
    : code(c), title(t), available(a), rented(r), age(age), publisher(pub), publishDate(pubd) {}

int Book::getCode() { return code; }
string Book::getTitle() { return title; }
int Book::getAvailable() { return available; }
int Book::getRented() { return rented; }
int Book::getAge() { return age; }
string Book::getPublisher() { return publisher; }
int Book::getPublishDate() { return publishDate; }

void Book::setCode(int c) { code = c; }
void Book::setTitle(string t) { title = t; }
void Book::setAvailable(int a) { available = a; }
void Book::setRented(int r) { rented = r; }
void Book::setAge(int a) { age = a; }
void Book::setPublisher(string p) { publisher = p; }
void Book::setPublishDate(int d) { publishDate = d; }

//----------------Children Book----------------
ChildrenBook::ChildrenBook() : age(0) {}
ChildrenBook::ChildrenBook(int c, string t, int a, int r, int ag)
    : Book(c, t, a, r, ag, "", 0) {
    age = a;
}

int ChildrenBook::getAge() { return age; }
void ChildrenBook::setAge(int a) { age = a; }

//----------------Computer Book----------------
ComputerBook::ComputerBook() : publisher("") {}
ComputerBook::ComputerBook(int c, string t, int a, int r, string p)
    : Book(c, t, a, r, 0, p, 0) {
    publisher = p;
}

string ComputerBook::getPublisher() { return publisher; }
void ComputerBook::setPublisher(string p) { publisher = p; }

//----------------Novel----------------
Novel::Novel() : publish_date(0) {}
Novel::Novel(int c, string t, int a, int r, int pd) : Book(c, t, a, r, 0, "", pd) {
    publish_date = pd;
}

int Novel::getPublishDate() { return publish_date; }
void Novel::setPublishDate(int pd) { publish_date = pd; }

// ------------Person------------------
Person::Person() : id(0), name(""), count(0) {}
Person::Person(int i, string n, int c, int code1, int code2, int code3) : id(i), name(n), count(c) {
    code[0] = code1;
    code[1] = code2;
    code[2] = code3;
}

int Person::getId() { return id; }
string Person::getName() { return name; }
int Person::getCount() { return count; }

void Person::setID(int i) { id = i; }
void Person::setName(string n) { name = n; }
void Person::setCount(int c) { count = c; }

//----------------Student----------------
Student::Student() : Person(0, "", 0, 0, 0, 0) {
    code[0] = 0;
    code[1] = 0;
}

Student::Student(int i, string n, int c, int code0, int code1)
    : Person(i, n, c, code0, code1, 0) {
    code[0] = code0;
    code[1] = code1;
}

void Student::setCode(int idx, int value) { code[idx] = value; }

//----------------Teacher----------------
Teacher::Teacher() : Person(0, "", 0, 0, 0, 0) {
    code[0] = 0;
    code[1] = 0;
    code[2] = 0;
}

Teacher::Teacher(int i, string n, int c, int code0, int code1, int code2)
    : Person(i, n, c, code0, code1, code2) {
    code[0] = code0;
    code[1] = code1;
    code[2] = code2;
}

//int Teacher::getCode(int idx) { return code[idx]; }
void Teacher::setCode(int idx, int value) { code[idx] = value; }

void showMenu() {
    cout << "----------------------------" << endl;
    cout << "            Menu" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Search a book" << endl;
    cout << "2. Rent a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Show my information" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "Select (1-5) : ";
}

void showCase1(Node* library[]) {
    int code;
    string title;
    Node* ptr = NULL;

    cout << "\nEnter code: ";
    cin >> code;

    cout << "Enter title: ";
    cin >> title;

    try {
        // Grab Head
        if (code > 1000 && code < 2000) {
            ptr = library[0];
        }
        else if (code > 2000 && code < 3000) {
            ptr = library[1];
        }
        else {
            ptr = library[2];
        }

        // Search
        while (ptr != NULL) {
            if (ptr->data.getTitle() == title) {
                break;
            }

            ptr = ptr->next;
        }
        if (ptr == NULL) {
            throw(1);
        }
        else {
            cout << title << "(" << code << ")" << " exists." << endl;
            if (code > 1000 && code < 2000) {
                cout << "category : children" << endl;
                cout << "age: " << ptr->data.getAge() << endl;
                cout << ptr->data.getAvailable() << " available, " << ptr->data.getRented() << " rented" << endl;
            }
            else if (code > 2000 && code < 3000) {
                cout << "category : computer" << endl;
                cout << "publisher : " << ptr->data.getPublisher() << endl;
                cout << ptr->data.getAvailable() << " available, " << ptr->data.getRented() << " rented" << endl;
            }
            else {
                cout << "category : novel" << endl;
                cout << "publish date : " << ptr->data.getPublishDate() << endl;
                cout << ptr->data.getAvailable() << " available, " << ptr->data.getRented() << " rented" << endl;
            }
        }
    }
    catch (int e) {
        if (e == 1) {
            cout << "Book not found." << endl;
        }
    }
}

void showCase2(Node* library[], pNode* people[]) {
    int id;
    string title;
    Node* ptr = NULL;
    pNode* peoplePtr = NULL;

    cout << "\nEnter your id: ";
    cin >> id;

    cout << "Enter title: ";
    cin >> title;

    // Max rented books
    int max;
    if (id <= 100) {
        max = 3;
    }
    else {
        max = 2;
    }

    // Grab Teacher or Student Head
    for (int i = 0; i < 2; i++) {
        peoplePtr = people[i];

        // Search
        while (peoplePtr != NULL) {
            if (peoplePtr->data.getId() == id) {
                break;
            }

            peoplePtr = peoplePtr->next;
        }

        if (peoplePtr != NULL) {
            break;
        }
    }

    // Grab Book Head
    for (int i = 0; i < 3; i++) {
        ptr = library[i];

        // Search
        while (ptr != NULL) {
            if (ptr->data.getTitle() == title) {
                break;
            }

            ptr = ptr->next;
        }

        if (ptr != NULL) {
            break;
        }
    }

    // Response Handling
    string response;
    cout << "\nYou are " << peoplePtr->data.getName() << ". You rented " << peoplePtr->data.getCount() << " book." << endl;
    cout << "Do you want to rent '" << ptr->data.getTitle() << "' (y/n)";
    cin >> response;

    try {
        if (response == "y") {
            if (peoplePtr->data.getCount() == max) {
                throw (1);
            }

            else if (ptr->data.getAvailable() == 0) {
                throw (2);
            }

            // This will cause issues
            else {
                peoplePtr->data.setCode(peoplePtr->data.getCount(), ptr->data.getCode());
                peoplePtr->data.setCount(peoplePtr->data.getCount() + 1);
                cout << "Rent Succeed. Check your info!" << endl;
            }
        }
    }
    catch (int e) {
        if (e == 1) {
            cout << "You already have " << max << " books." << endl;
        }
        if (e == 2) {
            cout << "Book is not available. (All rented out)." << endl;
        }
    }

}

void showCase3(Node* library[], pNode* people[]) {
    int id, bookCode;
    Node* ptr = NULL;
    pNode* peoplePtr = NULL;

    cout << "\nEnter your id : ";
    cin >> id;

    cout << "Enter the book code to return: ";
    cin >> bookCode;

    // Grab Teacher or Student Head
    for (int i = 0; i < 2; i++) {
        peoplePtr = people[i];

        // Search
        while (peoplePtr != NULL) {
            if (peoplePtr->data.getId() == id) {
                break;
            }

            peoplePtr = peoplePtr->next;
        }

        if (peoplePtr != NULL) {
            break;
        }
    }

    // Grab Book Head
    for (int i = 0; i < 3; i++) {
        ptr = library[i];

        // Search
        while (ptr != NULL) {
            if (ptr->data.getCode() == bookCode) {
                break;
            }

            ptr = ptr->next;
        }

        if (ptr != NULL) {
            break;
        }
    }

    // Response Handling
    string response;
    int idx;
    cout << "\nDo you want to return '" << ptr->data.getTitle() << "' (y/n)";
    cin >> response;

    if (peoplePtr->data.getCode(0) == ptr->data.getCode()) {
        idx = 0;
    }
    else if (peoplePtr->data.getCode(1) == ptr->data.getCode()) {
        idx = 1;
    }
    else if (peoplePtr->data.getCode(2) == ptr->data.getCode()) {
        idx = 2;
    }
    else {
        idx = -1;
    }

    try {
        if (response == "y") {
            if (idx == -1) {
                throw(1);
            }

            else {
                peoplePtr->data.setCode(idx, 0);
                peoplePtr->data.setCount(peoplePtr->data.getCount() - 1);
                cout << "Return Succeeded. Check your info!" << endl;
            }
        }
    }
    catch (int e) {
        if (e == 1) {
            cout << "Book not rented." << endl;
        }
    }
}

void showCase4(Node* library[], pNode* people[]) {
    int id;
    string name;
    pNode* peoplePtr;

    cout << "\nEnter your id: ";
    cin >> id;

    cout << "Enter your name: ";
    cin >> name;

    // Grab Teacher or Student Head
    for (int i = 0; i < 2; i++) {
        peoplePtr = people[i];

        // Search
        while (peoplePtr != NULL) {
            if (peoplePtr->data.getId() == id) {
                break;
            }

            peoplePtr = peoplePtr->next;
        }

        if (peoplePtr != NULL) {
            break;
        }
    }

    cout << "\nYou have rented " << peoplePtr->data.getCount() << " books." << endl;

    for (int i = 0; i < 3; i++) {
        int bookCode = peoplePtr->data.getCode(i);
        if (bookCode != 0) {
            cout << "Book Code: " << bookCode << endl;
            bool bookFound = false;

            // Search for the book in the library array
            for (int j = 0; j < 24; j++) {
                Node* current = library[j];
                while (current != NULL) {
                    if (current->data.getCode() == bookCode) {
                        cout << "Book Title: " << current->data.getTitle() << endl;
                        bookFound = true;
                        break; // Breaks only the inner loop
                    }
                    current = current->next;
                }

                if (bookFound) {
                    break; // Breaks the outer loop if the book is found
                }
            }
        }
    }
}
