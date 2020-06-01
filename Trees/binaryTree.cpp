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

// if there are n nodes in my tree

// Time: O(n)
// Space: O(n)

int check = 0;
void preOrder(TreeNode* root) {
	check++;
	if (root == NULL) {
		return;
	}

	// N L R
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

// Time: O(n)
// Space: O(n)
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

// Time: O(n)
// Space: O(n)
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
// Time: O(n)
// Space: O(n)
void postOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

// sum of all nodes
// Time: O(n)
// Space: O(n)
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
// Time: O(n)
// Space: O(n)
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

// Time: O(n)
// Space: O(n)
int height(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalHeight = max(leftHeight, rightHeight) + 1;
	return totalHeight;
}


// Time: O(n^2)
int diameterOfBinaryTree(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDiameter = diameterOfBinaryTree(root->left);
	int rightDiameter = diameterOfBinaryTree(root->right);

	int leftHeight = height(root->left) + 1;
	int rightHeight = height(root->right) + 1;

	int myDiameter = leftHeight + rightHeight;

	int maxDiameter = max(myDiameter, max(leftDiameter, rightDiameter));

	return maxDiameter;
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

	// cout << "Height of the tree is " << height(root) << endl;


	// preOrder(root);
	// cout << endl << "**************" << endl;
	// cout << check << endl;

	return 0;
}

// Input Tree
// 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1