#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* builtBST(TreeNode* root, int data) {
	if (root == NULL) {
		root = new TreeNode(data);
		return root;
	}

	if (data > root->val) {
		root->right = builtBST(root->right, data);
	} else {
		root->left = builtBST(root->left, data);
	}

	return root;
}

TreeNode* insert(TreeNode* root) {

	int data;
	cin >> data;

	while (data != -1) {
		root = builtBST(root, data);
		cin >> data;
	}

	return root;
}

void inOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	// N L R
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

// Time: O(h) -> O(n)
bool searchInBST(TreeNode* root, int key) {
	if (root == NULL) {
		return false;
	}

	if (root->val == key) {
		return true;
	}

	if (key > root->val) {
		// then my answert lies in the right subtree
		return searchInBST(root->right, key);
	} else {
		// my answert lies in the left subtree
		return searchInBST(root->left, key);
	}
}

bool isBST(TreeNode* root) {

}

int main() {

	TreeNode* root = NULL;
	root = insert(root);

	// cout << "********* INORDER *******" << endl;
	// inOrder(root);
	// cout << endl;

	// cout << "********* PREORDER *******" << endl;
	// preOrder(root);
	// cout << endl;

	return 0;
}

// Input Tree
// 8 5 7 6 3 12 10 14 -1