#include "project.h"
#include <fstream>
#include <iostream>
using namespace std;

// Sorting Function from Lab
Node* sort(Node* head, Node* ptr) {
    Node* rep = head;
    Node* prev = NULL;

    while (rep != NULL && ptr->data.getCode() > rep->data.getCode()) {
        prev = rep;
        rep = rep->next;
    }

    // End of the list
    if (rep == NULL) {
        prev->next = ptr;
    }

    // Middle of the list
    else {
        prev->next = ptr;
        ptr->next = rep;
    }

    return head;
}

// Sort function for People Nodes
pNode* pSort(pNode* head, pNode* ptr) {
    pNode* rep = head;
    pNode* prev = NULL;

    while (rep != NULL && ptr->data.getId() > rep->data.getId()) {
        prev = rep;
        rep = rep->next;
    }

    // End of the list
    if (rep == NULL) {
        prev->next = ptr;
    }

    // Middle of the list
    else {
        prev->next = ptr;
        ptr->next = rep;
    }

    return head;
}

int main() {
    ifstream infile;
    infile.open("book.txt");
    if (infile.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    // Children book
    int code, age, available, rent;
    string title;

    // Computer book
    string publisher;

    // Novel
    int published_date;

    // Head pointers
    Node* ChildHead = NULL;
    Node* CompHead = NULL;
    Node* NovelHead = NULL;
    Node* childPtr = NULL;
    Node* compPtr = NULL;
    Node* novelPtr = NULL;

    while (!infile.eof()) {
        infile >> code >> title;

        if (code > 1000 && code < 2000) {
            infile >> age;
        }

        else if (code > 2000 && code < 3000) {
            infile >> publisher;
        }

        else if (code > 3000 && code < 4000) {
            infile >> published_date;
        }

        infile >> available >> rent;

        // Set up according to the book type
        // Children's Book
        if (code > 1000 && code < 2000) {
            ChildrenBook cBook(code, title, available, rent, age);
            childPtr = new Node(cBook);

            if (ChildHead == NULL) {
                ChildHead = childPtr;
            }

            else if (childPtr->data.getCode() < ChildHead->data.getCode()) {
                childPtr->next = ChildHead;
                ChildHead = childPtr;
            }

            else {
                ChildHead = sort(ChildHead, childPtr);
            }
        }

        // Computer Book
        else if (code > 2000 && code < 3000) {
            ComputerBook compBook(code, title, available, rent, publisher);
            compPtr = new Node(compBook);

            if (CompHead == NULL) {
                CompHead = compPtr;
            }

            else if (compPtr->data.getCode() < CompHead->data.getCode()) {
                compPtr->next = CompHead;
                CompHead = compPtr;
            }

            else {
                CompHead = sort(CompHead, compPtr);
            }
        }

        // Novel
        else if (code > 3000 && code < 4000) {
            Novel nBook(code, title, available, rent, published_date);
            novelPtr = new Node(nBook);

            if (NovelHead == NULL) {
                NovelHead = novelPtr;
            }

            else if (novelPtr->data.getCode() < NovelHead->data.getCode()) {
                novelPtr->next = NovelHead;
                NovelHead = novelPtr;
            }

            else {
                NovelHead = sort(NovelHead, novelPtr);
            }
        }
    }

    // Linked List Array
    Node* library[3];
    library[0] = ChildHead;
    library[1] = CompHead;
    library[2] = NovelHead;

    infile.close();

    // Students and Teachers
    infile.open("person.txt");
    if (infile.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }


    string name;
    int id, count;
    pNode* tHead = NULL;
    pNode* sHead = NULL;
    pNode* tPtr = NULL;
    pNode* sPtr = NULL;


    while (!infile.eof()) {
        infile >> id >> name >> count;
        int bookcode[3] = { 0,0,0 };

        for (int i = 0; i < count; i++) {
            infile >> bookcode[i];
        }

        // Teacher Linked List
        if (id < 100) {
            Teacher teacher(id, name, count, bookcode[0], bookcode[1], bookcode[2]);
            tPtr = new pNode(teacher);

            if (tHead == NULL) {
                tHead = tPtr;
            }

            else if (tPtr->data.getId() < tHead->data.getId()) {
                tPtr->next = tHead;
                tHead = tPtr;
            }

            else {
                tHead = pSort(tHead, tPtr);
            }

        }

        // Student Linked List
        else {
            Student student(id, name, count, bookcode[0], bookcode[1]);
            sPtr = new pNode(student);

            if (sHead == NULL) {
                sHead = sPtr;
            }

            else if (sPtr->data.getId() < sHead->data.getId()) {
                sPtr->next = sHead;
                sHead = sPtr;
            }

            else {
                sHead = pSort(sHead, sPtr);
            }
        }

    }

    // Student Linked List Array
    pNode* people[2];
    people[0] = tHead;
    people[1] = sHead;

    int input;
    do {
        showMenu();
        cin >> input;

        switch (input) {
        case 1:
            showCase1(library);
            break;

        case 2:
            showCase2(library, people);
            break;

        case 3:
            showCase3(library, people);
            break;

        case 4:
            showCase4(library, people);
            break;

        case 5:
            break;
        }
    } while (input != 5);
    return 0;
}
