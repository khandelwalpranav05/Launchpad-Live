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
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

// sum of all nodes
int sumOfNodes(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int totalSum = leftSum + root->val + rightSum;
	return totalSum;
}

// search if a key exist in the tree or not
bool search(TreeNode* root, int key) {
	if (root == NULL) {
		return false;
	}

	if (root->val == key) {
		return true;
	}

	bool leftSearch = search(root->left, key);
	bool rightSearch = search(root->right, key);

	// if (leftSearch or rightSearch) {
	// 	return true;
	// }
	// return false;
	return leftSearch or rightSearch;
}

int height(TreeNode* root) {

}

int main() {

	TreeNode* root = NULL;
	root = builtTree(root);

	// cout << "Root value is " << root->val << endl;

	// preOrder(root);
	// cout << endl;

	// inOrder(root);
	// cout << endl;

	// cout << "Total number of nodes " << countNodes(root) << endl;

	// cout << "Sum of nodes " << sumOfNodes(root) << endl;

	// int key = 4;
	// if (search(root, key)) {
	// 	cout << "Found The Key!" << endl;
	// } else {
	// 	cout << "Not Found!" << endl;
	// }


	return 0;
}

// Input Tree
// 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1