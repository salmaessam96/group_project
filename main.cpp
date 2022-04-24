#include "list.h"
#include "TreapNode.h"
#include <iostream>
using namespace std;

int main() {
	while (true) {
		int choice;
		list l;
		l.file();
		BST* root = NULL;//
		BST child;//         both for re adjusting the Treap

	s:
		cout << "Hello,Welcome to our Project" << endl << "1-Login" << endl << "2-Exit" << endl;
		cin >> choice;

		if (choice == 1) {
		k:

			string userName;
			cout << "User Name: " << endl;
			cin >> userName;

			if (l.bsearch(userName) == true)//bsearch checks if user is in the file
			{
				node* user = l.search(userName);//search returns the user object (node)
				l.friends(user);// building the Treap for user from the file
				while (true)
				{
				r:
					int choice2;
					cout << "1-List All Friends" << endl << "2-Search by Username" << endl << "3-Add Friend" << endl;
					cout << "4-Remove Friend" << endl << "5-people You may Know" << endl << "6-Logout" << endl;
					cin >> choice2;

					if (choice2 == 1) {//List Friends
						if (l.bsearch(userName)) {
							user->setChild(child);
							user->setRoot(root);
							l.friends(user);
							cout << user->getName() << endl;
							user->child.Inorder(user->root);// list the Treap
							cout << endl << endl;
						}
					}
					else if (choice2 == 2) {//Search UserName
						cout << "Enter User name want to search" << endl;
						string n;
						cin >> n;
						node* u = l.search(n);
						string temp = n + ":" + u->getName();//user stored in the TREAP by this struct
						if (user->child.bsearch(user->root, temp)) {
							cout << n << u->getName() << u->getmail() << endl;

						}
						else {
							cout << " User Not Found in Friend List" << endl;
						}

					}
					else if (choice2 == 3) {//Add Friend
						if (l.bsearch(userName)) {
							node* user = l.search(userName);
							cout << user->getName() << endl;
							cout << "Enter user Name want to add" << endl;
							string frnd;
							cin >> frnd;
							l.addFriend(user, frnd);

							user->setChild(child);//
							user->setRoot(root);// to re adjust the TREAP
							l.friends(user);//
						}

					}
					else if (choice2 == 4) { //Remove Friend
						cout << "Enter User name want to remove" << endl;
						string n;
						cin >> n;
						node* u = l.search(n);
						string temp = n + ":" + u->getName();
						if (user->child.bsearch(user->root, temp)) {
							l.removeFriend(user, n);
							cout << "Done" << endl << endl;
						}
						else {
							cout << "User Not Found in Friend List" << endl << endl;
							goto r;
						}
					}
					else if (choice2 == 5) { //Pepole you May Know

						cout << user->getName() << endl;
						l.mayKnow(user);
						cout << endl << endl;
						user->setChild(child);//
						user->setRoot(root);// to re adjust the TREAP
						l.friends(user);//

					}
					else if (choice2 == 6) {
						cout << "You LogedOut" << endl;
						goto s;
					}
				}
			}
			else {
				goto k;
			}
		}
		else if (choice == 2) {
			return 0;
		}
	}
}
