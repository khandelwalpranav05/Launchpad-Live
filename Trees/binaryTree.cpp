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

	int leftHeight = height(root->left) + 1; // O(n)
	int rightHeight = height(root->right) + 1; // O(n)

	int myDiameter = leftHeight + rightHeight;

	int maxDiameter = max(myDiameter, max(leftDiameter, rightDiameter));

	return maxDiameter;
}

class DiaHeight {
public:
	int diameter;
	int height;
};

// Time: O(n)
DiaHeight diameterOptimized(TreeNode* root) {
	DiaHeight val;
	if (root == NULL) {
		val.diameter = 0;
		val.height = -1;

		return val;
	}

	// update the height and diameter of val object and then return

	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	int leftDiameter = leftPair.diameter;
	int rightDiameter = rightPair.diameter;

	int leftHeight = leftPair.height;
	int rightHeight = rightPair.height;

	int myDiameter = leftHeight + 2 + rightHeight;

	int maxDiameter = max(myDiameter, max(leftDiameter, rightDiameter));
	val.diameter = maxDiameter;

	val.height = max(leftHeight, rightHeight) + 1;
	return val;
}


// Time: O(n^2)
bool heightBalanced(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	bool leftBalance = heightBalanced(root->left);
	bool rightBalance = heightBalanced(root->right);

	if (leftBalance == false or rightBalance == false) {
		return false;
	}

	// if you're here that means
	// both my left subtree and right subtree are balanced

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int diff = abs(leftHeight - rightHeight);

	if (diff > 1) {
		return false;
	}
	return true;
}

pair<bool, int> heightBalancedOptimized(TreeNode* root) {
	pair<bool, int> val; // object that will be eventually returned by the function

	if (root == NULL) {
		val.first = true;
		val.second = -1;
		return val;
	}

	pair<bool, int> leftPair = heightBalancedOptimized(root->left);
	pair<bool, int> rightPair = heightBalancedOptimized(root->right);

	bool leftBalance = leftPair.first;
	bool rightBalance = rightPair.first;

	int leftHeight = leftPair.second;
	int rightHeight = rightPair.second;

	int myHeight = max(leftHeight, rightHeight) + 1;
	val.second = myHeight;

	if (leftBalance == false or rightBalance == false) {
		val.first = false;
		return val;
	}

	int diff = abs(leftHeight - rightHeight);

	if (diff > 1) {
		val.first = false;
	} else {
		val.first = true;
	}

	return val;
}

void display(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " -> ";
	}
	cout << endl;
}

void printRootToLeaf(TreeNode* root, vector<int> ans) {
	if (root == NULL) {
		return;
	}

	ans.push_back(root->val);

	if (root->left == NULL and root->right == NULL) {
		display(ans);
		return;
	}

	printRootToLeaf(root->left, ans);
	printRootToLeaf(root->right, ans);
}

// Time: O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL) {
		return NULL;
	}

	if (root == p or root == q) {
		return root;
	}

	TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
	TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

	if (leftLCA == NULL and rightLCA == NULL) {
		return NULL;
	}

	if (leftLCA != NULL and rightLCA != NULL) {
		return root;
	}

	// either my leftLCA is null or my rightLCA is null
	if (leftLCA == NULL) {
		return rightLCA;
	} else {
		return leftLCA;
	}
}

int helper(TreeNode* root, int &maxValue) {
	if (root == NULL) {
		return 0;
	}

	int leftMax = helper(root->left, maxValue);
	int rightMax = helper(root->right, maxValue);

	leftMax = max(leftMax, 0);
	rightMax = max(rightMax, 0);

	int maxPathSumPassingThroughMe = leftMax + root->val + rightMax;

	maxValue = max(maxValue, maxPathSumPassingThroughMe);

	int pathReturnedToParent = max(leftMax + root->val, rightMax + root->val);
	return pathReturnedToParent;
}

int maxPathSum(TreeNode* root) {
	int maxValue = INT_MIN;

	helper(root, maxValue);

	return maxValue;
}

// int func() {

// 	int a = 5;
// 	return a;
// 	OR
// 	return 5;
// }

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

	// if (heightBalanced(root)) {
	// 	cout << "Balanced !" << endl;
	// } else {
	// 	cout << "Not Balanced" << endl;
	// }
	vector<int> temp;
	printRootToLeaf(root, temp);

	return 0;
}

// Input Tree
// 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1