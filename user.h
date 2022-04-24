#pragma once
#include <string>
using namespace std;

class node {
public:
	string username, email, name, value;
	node* next; 
	BST* root = NULL;
	BST child;
	node() {
		next = NULL;
		value = "";
	}
	node(const string v) {
		value = v;
	}
	void setNext(node *n) {
		next = n;
	}
	node* getNext() {
		return next;
	}
	void setValue(string v) {
		value = v;
	}
	string getValue(){
		return value;
	}
	void setuserName(string u) {
		username = u;
	}
	string getuserName() {
		return username;
	}
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	void setmail(string m) {
		email = m;
	}
	string getmail() {
		return email;
	}
	void setRoot(BST* r) {
		root = r;
	}
	void setChild(BST ch) {
		child = ch;
	}
};