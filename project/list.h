#pragma once
#include "node.h"
#include <iostream>
#include <fstream>

using namespace std;

class list{
public:
	node* head;
	node* tail;
	list() {
		head = NULL;
		tail = NULL;
		file();
	}
	void file() {
		string item, a[9];
		int i = 0;
		ifstream myfile("all-users.in", ios::in);
		while (getline(myfile, item)) {
			a[i] = item;
			i++;
		}
		extract(a);
	}
	void extract(string a[]) {
		string item;
		int count=0,i=0;
		while (i!=9) {
			node* p = new node;
			p->value = a[i];
			if (count == 0) {
				head = tail = p;
				p->next =  NULL;
			}
			else {
				p->next = NULL;
				tail->next = p;
				tail = p;
			}
			i++;
			count++;
		}
		tail->next = NULL;
		split();
	}
	void search(string item){
		node* current = head;
		while (current != NULL){
			if (current->value == item)
				break;
			current = current->next;

			if (current == NULL) {
				cout << "This user is not in the list\n";
				return;
			}

		}
	}
	void split(){
		node* current = head;
		string s,token, b = ",",a[3];
		while (current != NULL) {
			s = current->value;
			size_t pos = 0;
			int i = 0;
			while ((pos = s.find(b)) != string::npos) {
				token = s.substr(0, pos);
				a[i] = token;
				s.erase(0, pos + b.length());
				i++;
			}
			a[2] = s;
			current->username = a[0];
			current->name = a[1];
			current->email = a[2];
			current = current->next;
		}
	}
	void display() {
		node* current = head;
		int i=1;
		while (current != NULL) {
			cout << "username: " << current->username << "\nname:" << current->name << "\ne-mail:" << current->email << endl<<"-------"<<endl;
			current = current->next;
			i++;
		}
	}
};