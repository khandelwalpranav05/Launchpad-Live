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

bool isSameTree(TreeNode* p, TreeNode* q) {
	//BASE CASE
	if (p == NULL and q == NULL) {
		return true;
	}

	if (p == NULL or q == NULL) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	}

	bool isLeftSubtreeSame = isSameTree(p->left, q->left);
	bool isRightSubtreeSame = isSameTree(p->right, q->right);

	return isLeftSubtreeSame and isRightSubtreeSame;
}

bool isSymmetric(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	return isMirror(root->left, root->right);
}

bool isMirror(TreeNode* p, TreeNode* q) {
	if (p == NULL and q == NULL) {
		return true;
	}

	if (p == NULL or q == NULL) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	}

	bool leftMirror = isMirror(p->left, q->right);
	bool rightMirror = isMirror(p->right, q->left);

	return leftMirror and rightMirror;
}

bool isSubtree(TreeNode* s, TreeNode* t) {
	if (s == NULL) {
		return false;
	}

	if (isSameTree(s, t)) {
		return true;
	}

	bool maybeLeftMatch = isSubtree(s->left, t);
	bool maybeRightMatch = isSubtree(s->right, t);

	return maybeLeftMatch or maybeRightMatch;
}

int minDepth(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDepth = minDepth(root->left);
	int rightDepth = minDepth(root->right);

	if (leftDepth == 0) {
		return rightDepth + 1;
	}

	if (rightDepth == 0) {
		return leftDepth + 1;
	}

	return min(leftDepth, rightDepth) + 1;
}


void rightPriorityPreorder(TreeNode* root, int level, int &firstTime, vector<int> &res) {
	if (root == NULL) {
		return;
	}

	if (level == firstTime) {
		res.push_back(root->val);
		firstTime++;
	}

	rightPriorityPreorder(root->right, level + 1, firstTime, res);
	rightPriorityPreorder(root->left, level + 1, firstTime, res);
}

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	int firstTime = 0;

	rightPriorityPreorder(root, 0, firstTime, res);

	return res;
}


bool helper(TreeNode* root, ListNode* head) {
	// BASE CASE
	if (head == NULL) {
		return true;
	}

	if (root == NULL) {
		return false;
	}

	if (head->val != root - val) {
		return false;
	}

	bool leftRestLinkedList = helper(root->left, head->next);
	bool rightRestLinkedList = helper(root->right, head->next);

	return leftRestLinkedList or rightRestLinkedList;
}

bool isSubPath(ListNode* head, TreeNode* root) {
	if (root == NULL) {
		return false;
	}

	if (helper(root, head)) {
		return true;
	}

	bool isSubPathLeftSubtree = isSubPath(head, root->left);
	bool isSubPathRightSubtree = isSubPath(head, root->right);

	return isSubPathLeftSubtree or isSubPathRightSubtree;
}

void rootToLeaf(TreeNode* root, vector<int> freq, int &count) {
	if (root == NULL) {
		return;
	}

	freq[root->val] += 1;

	if (root->left == NULL and root->right == NULL) {
		int check = 0;

		for (int i = 1; i <= 9; i++) {
			int freqCount = freq[i];

			if (freqCount & 1) {
				check++;
			}
		}

		if (check <= 1) {
			count++;
		}

		return;
	}


	rootToLeaf(root->left, freq, count);
	rootToLeaf(root->right, freq, count);
}

int pseudoPalindromicPaths (TreeNode* root) {
	vector<int> freq(10, 0);

	int count = 0;

	rootToLeaf(root, freq, count);

	return count;
}


void convertToGreaterSumTree(TreeNode* root, int &sum) {
	if (root == NULL) {
		return;
	}

	convertToGreaterSumTree(root->right, sum);

	// my work (node work)
	root->val += sum;
	sum = root->val;

	convertToGreaterSumTree(root->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {
	int sum = 0;

	convertToGreaterSumTree(root, sum);
	return root;
}

int main() {


	return 0;
}