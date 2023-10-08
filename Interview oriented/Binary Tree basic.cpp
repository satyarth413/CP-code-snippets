#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
	int data;
	Tree* left;
	Tree* right;
	Tree(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

// insert 0
//    1
//   / \
// -1   2
//  \
//   0
Tree* insert(Tree* root, int key)
{
	if (root == NULL)
	{
		Tree* newNode = new Tree(key);
		return newNode;
	}
	if (root->data < key)
		root->right = insert(root->right, key);
	else if (root->data > key)
		root->left = insert(root->left, key);
	return root;
}

void inorder(Tree* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

int main()
{
	Tree* root = new Tree(5);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 6);
	root = insert(root, 1);
	inorder(root);
}
