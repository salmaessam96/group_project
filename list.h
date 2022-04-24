#pragma once
#include "user.h"
#include <iostream>
#include <fstream>

#include<stdio.h>
#include<conio.h>

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
	node* search(string item){
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

	bool bsearch(string item) {
		node* current = head;
		while (current != NULL) {
			if (current->username == item) {
				return true;
				break;
			}
			current = current->next;

			if (current == NULL) {
				cout << "This user is not in the list\nPlease Enter the right User Name.\n\n";
				return false;
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
		while (current != NULL) {
			cout << "username: " << current->username << "\nname:" << current->name << "\ne-mail:" << current->email << endl<<"-------"<<endl;
			current = current->next;
		}
	}


	void friends(node* node)
	{

		int pos = 0;

		string temp;
		string temp2;
		string frnd;

		int i = 0;
		ifstream myfile("all-users-relations.in", ios::in);
		while (!myfile.eof()) {
			string item = "";
			getline(myfile, item);
			//finding ',' position
			while ((pos = item.find(",")) != string::npos) {
				temp = item.substr(0, pos);
				temp2 = item.substr((pos + 2), item.size() - 1);//to skip the coma and space after it
				if (temp == node->username)
				{
					frnd = temp2;

					node->root = node->child.insert(node->root, search(frnd)->getuserName() + ":" + search(frnd)->getName());


				}
				else if (temp2 == node->username)
				{

					frnd = item.substr(0, pos);
					node->root = node->child.insert(node->root, search(frnd)->getuserName() + ":" + search(frnd)->getName());


				}

				break;
			}
			i++;
		}
	}

	void addFriend(node* node, string user)
	{

		if (bsearch(user))
		{
			string temp = user + ":" + search(user)->getName();
			if (!node->child.bsearch(node->root, temp))
			{
				ofstream output;
				ifstream input;
				input.open("all-users-relations.in");
				output.open("all-users-relations.in", ios::app);
				if (input.is_open())
				{
					output << node->getuserName() + ", " + user << endl;
					cout << "You are now friends" << endl;
					input.close();
					output.close();
				}
				node->root = node->child.insert(node->root, temp);

			}

			else
			{
				cout << "youre already friends\n";
			}
		}
		else {
			cout << "Not Exist" << endl;
		}
	}

	void removeFriend(node* node, string user)
	{
		ofstream ofs;
		ofs.open("temp.in", ofstream::out | ios::app);
		int pos = 0;

		string temp;
		string temp2;
		string frnd;

		int i = 0;
		ifstream myfile("all-users-relations.in", ios::in | ios::app);
		while (!myfile.eof()) {
			string item = "";
			getline(myfile, item);

			//finding ',' position
			while ((pos = item.find(",")) != string::npos) {
				temp = item.substr(0, pos);
				temp2 = item.substr((pos + 2), item.size() - 1);//to skip the coma and space after it

				if ((temp == node->username && temp2 == user) || (temp2 == node->username && temp == user))
				{

					break;



				}
				else
				{
					ofs << item << endl;
					break;
				}
			}
			i++;
		}
		myfile.close();
		remove("all-users-relations.in");
		ifstream  src("temp.in", std::ios::binary);
		ofstream  dst("all-users-relations.in", std::ios::binary);

		dst << src.rdbuf();
		src.close();
		ofs.close();
		remove("temp.in");
		BST* root = NULL;
		BST child;
		node->setChild(child);
		node->setRoot(root);

		friends(node);
	}

	void mayKnow(node* nod) {

		int count = 5;
		node* current = head;

		for (int i = 0; i < 8; i++) {

			string temp = current->getuserName() + ":" + current->getName();
			if (!nod->child.bsearch(nod->root, temp) && current->getuserName() != nod->getuserName())
			{
				cout << temp; recommend(count); count--; cout << endl;
			}

			current = current->getNext();
		}
	}
	void recommend(int count)
	{

		if (count > 0)
		{
			cout << "(recommended)";


		}
	}
};