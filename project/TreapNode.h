#include<iostream>
#include "list.h"
using namespace std;

class BST
{
public:
	int priority;
	string data;
	BST* left, * right;
	BST();
	BST(string);
	BST* insert(BST*, string);
	BST* search(BST*,string);
	BST* rightRotate(BST*);
	BST* leftRotate(BST*);
	void Inorder(BST*);
	void files();
};
BST::BST(){
	priority = 0;
	data = "";
	left=NULL;
	right=NULL;
}
BST::BST(string value)
{
	priority = rand() % 100;
	data = value;
	left = right = NULL;
}
BST* BST::rightRotate(BST* y)
{
	BST* x = y->left, * T2 = x->right;
	x->right = y;
	y->left = T2;
	return x;
}
BST* BST:: leftRotate(BST* x) {
	BST* y = x->right, * T2 = y->left;
	y->left = x;
	x->right = T2;
	return y;
}
BST* BST::insert(BST* root, string value)
{
	if (root==nullptr)
	{
		return new BST(value);
	}
	if (value > root->data&&root->right==NULL)
	{
		root->right = insert(root->right, value);
		if (root->right->priority > root->priority)
			root = leftRotate(root);
	}
	else if (value >= root->data) {
		root->right = insert(root->right, value);
	}
	else if(value< root->data&&root->left==NULL)
	{
		root->left = insert(root->left, value);
		if (root->left->priority > root->priority)
			root = rightRotate(root);
	}
	else if (value <= root->data) {
		root->left = insert(root->left, value);
	}
	return root;
}
BST* BST::search(BST*root, string key) {
	if (root==NULL||root->data == key) {
		return root;
	}
	if (root->data < key)
		return search(root->right, key);
	if(root->data>key)
		return search(root->left, key);
}
void BST::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}
void BST:: files(){
	string item;
	BST b, * root = NULL;
	ifstream myfile("all-users-relations.in", ios::in);
	while (getline(myfile, item)) {
		root = b.insert(root, item);
	}
	b.Inorder(root);
}