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

// for building all trees bt as well as bst
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

// for only building bst
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

bool isBST(TreeNode* root, int minRange = INT_MIN, int maxRange = INT_MAX) {
	if (root == NULL) {
		return true;
	}

	bool leftBST = isBST(root->left, minRange, root->val);
	bool rightBST = isBST(root->right, root->val, maxRange);

	if (leftBST and rightBST and root->val > minRange and root->val < maxRange) {
		return true;
	}

	return false;
}

class TreeDetail {
public:
	bool bst;
	int size;
	int minValue;
	int maxValue;
};

TreeDetail largestBSTinBinaryTree(TreeNode* root) {
	TreeDetail val; // object that will be returned by the function

	if (root == NULL) {
		val.bst = true;
		val.size = 0;
		val.minValue = INT_MAX;
		val.maxValue = INT_MIN;
		return val;
	}

	TreeDetail leftDetail = largestBSTinBinaryTree(root->left);
	TreeDetail rightDetail = largestBSTinBinaryTree(root->right);

	// leftBST and rightBST and root value > maxValue on left and root < minValue on right
	if (leftDetail.bst == false or rightDetail.bst == false or root->val > rightDetail.minValue or root->val < leftDetail.maxValue) {
		// I'm not a bst
		val.bst = false;
		val.size = max(leftDetail.size, rightDetail.size);
		return val;
	}

	// if i'm here that means I am a BST
	val.bst = true;
	val.size = leftDetail.size + rightDetail.size + 1;

	// before returning I've to update my minValue as well as maxValue

	int myMinValue;
	if (root->left == NULL) {
		myMinValue = root->val;
	} else {
		myMinValue = leftDetail.minValue;
	}

	int myMaxValue;
	if (root->right == NULL) {
		myMaxValue = root->val;
	} else {
		myMaxValue = rightDetail.maxValue;
	}

	val.minValue = myMinValue;

	val.maxValue = myMaxValue;

	return val;
}

void kthSmallestHelper(TreeNode* root, int &k, int &ans) {
	if (root == NULL) return;

	kthSmallestHelper(root->left, k, ans);

	// instead of printing
	k--;
	if (k == 0) {
		ans = root->val;
	}

	kthSmallestHelper(root->right, k, ans);
}

int kthSmallest(TreeNode* root, int k) {
	int ans;
	kthSmallestHelper(root, k, ans);

	return ans;
}

int preOrderIndex = 0;
TreeNode* builtTreeFromPreorderInorder(int pre[], int in[], int start, int end) {
	// base CASE
	if (start > end) {
		return NULL;
	}

	int data = pre[preOrderIndex];
	TreeNode* root = new TreeNode(data);

	int mid;

	for (int i = start; i <= end; i++) {
		if (in[i] == data) {
			mid = i;
			break;
		}
	}

	preOrderIndex++;

	root->left = builtTreeFromPreorderInorder(pre, in, start, mid - 1);
	root->right = builtTreeFromPreorderInorder(pre, in, mid + 1, end);

	return root;
}

// generate the preorder orientation with null values included
void serialize(TreeNode* root) {

}

int main() {

	// TreeNode* root = NULL;
	// root = insert(root);

	// cout << "********* INORDER *******" << endl;
	// inOrder(root);
	// cout << endl;

	// cout << "********* PREORDER *******" << endl;
	// preOrder(root);
	// cout << endl;

	// cout << isBST(root) << endl;

	// cout << "Largest BST in a BT" << endl;
	// TreeNode* root = NULL;
	// root = builtTree(root);

	// TreeDetail val = largestBSTinBinaryTree(root);

	// cout << " Size is " << val.size << endl; // 7

	int pre[] = {4, 2, 1, 3, 5, 8, 7};
	int in[] = {1, 2, 3, 4, 8, 5, 7};
	int n = 7;



	return 0;
}

// Input Tree
// 8 5 7 6 3 12 10 14 -1

// Input for largest bst in a bt
// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1