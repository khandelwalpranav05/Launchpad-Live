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

TreeNode* builtTree(TreeNode* root) {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	// if the data is not -1
	if (root == NULL) {
		root = new TreeNode(data);
	}

	root->left =  builtTree(root->left); // will return me the address of my leftchild node
	root->right =  builtTree(root->right); // will return me the adress of rightchild node

	return root;
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

void inOrder(TreeNode* root) {
	// BASE CASE
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

// in a tree problem you are just given a root node

int countNodes(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int totalCount = leftCount + 1 + rightCount;
	return totalCount;
}

// Postorder (L R N)
void postOrder(TreeNode* root) {

}

// sum of all nodes
int sumOfNodes(TreeNode* root) {

}

// search
bool search(TreeNode* root, int key) {

}

int main() {

	TreeNode* root = NULL;
	root = builtTree(root);

	// cout << "Root value is " << root->val << endl;

	// preOrder(root);
	// cout << endl;

	// inOrder(root);
	// cout << endl;

	cout << "Total number of nodes " << countNodes(root) << endl;

	return 0;
}

// Input Tree
// 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1