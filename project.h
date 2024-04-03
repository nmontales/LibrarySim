#ifndef PROJECT
#define PROJECT
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
public:
	Book();
	Book(int c, string t, int a, int r, int age, string pub, int pubd);

	int getCode();
	string getTitle();
	int getAvailable();
	int getRented();
	virtual int getAge();
	virtual string getPublisher();
	virtual int getPublishDate();


	void setCode(int c);
	void setTitle(string t);
	void setAvailable(int a);
	void setRented(int r);
	virtual void setAge(int a);
	virtual void setPublisher(string p);
	virtual void setPublishDate(int d);


private:
	int code;
	string title;
	int available;
	int rented;
	int age;
	string publisher;
	int publishDate;
};

class ChildrenBook : public Book {
public:
	ChildrenBook();
	ChildrenBook(int c, string t, int a, int r, int ag);

	int getAge() override;
	void setAge(int ag) override;

private:
	int age;
};

class ComputerBook : public Book {
public:
	ComputerBook();
	ComputerBook(int c, string t, int a, int r, string p);

	string getPublisher() override;
	void setPublisher(string p) override;

private:
	string publisher;
};

class Novel : public Book {
public:
	Novel();
	Novel(int c, string t, int a, int r, int pd);

	int getPublishDate() override;
	void setPublishDate(int pd) override;

private:
	int publish_date;
};

class Person {
public:
	Person();
	Person(int i, string n, int c, int code1, int code2, int code3);

	int getId();
	string getName();
	int getCount();

	void setID(int i);
	void setName(string n);
	void setCount(int c);

	int getCode(int idx) { return code[idx]; }
	void setCode(int idx, int val) { code[idx] = val; }

private:
	int id;
	string name;
	int count;
	int code[3];
};

class Student : public Person {
public:
	Student();
	Student(int i, string n, int c, int code0, int code1);

	int getCode(int idx) { return code[idx]; }
	void setCode(int idx, int value);

private:
	int code[2];
};

class Teacher : public Person {
public:
	Teacher();
	Teacher(int i, string n, int c, int code0, int code1, int code2);

	int getCode(int idx) { return code[idx]; }
	void setCode(int idx, int value);

private:
	int code[3];
};

struct Node {
	Book data;
	Node* next;

	Node(Book x) : data(x), next(nullptr) {}
};

struct pNode {
	Person data;
	pNode* next;

	pNode(Person x) : data(x), next(nullptr) {}
};




// Print Functions

void showMenu();

void showCase1(Node* library[3]);

void showCase2(Node* library[3], pNode* people[2]);

void showCase3(Node* library[3], pNode* people[2]);

void showCase4(Node* library[3], pNode* people[2]);

#endif /* PROJECT */
