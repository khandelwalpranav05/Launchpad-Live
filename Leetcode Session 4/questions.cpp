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

string helper(string str) {
	stack<char> s;

	for (int i = 0; i < str.length(); i++) {

		char ch = str[i];

		if (ch == '#') {
			if (!s.empty()) {
				s.pop();
			}
		} else {
			s.push(ch);
		}
	}

	string res = "";

	while (!s.empty()) {
		char ch = s.top();
		s.pop();

		// res+=ch;
		res.push_back(ch);
	}

	return res;
}

bool backspaceCompare(string S, string T) {

	string val1 = helper(S);
	string val2 = helper(T);

	return val1 == val2;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	int carry = 0;

	ListNode* dummy = new ListNode(0);
	ListNode* curr = dummy;

	while (l1 != NULL or l2 != NULL or carry != 0) {
		if (l1 != NULL) {
			carry += l1->val;
			l1 = l1->next;
		}

		if (l2 != NULL) {
			carry += l2->val;
			l2 = l2->next;
		}

		int data = carry % 10; // unit value of my current carry
		carry = carry / 10;

		ListNode* node = new ListNode(data);
		curr->next = node;
		curr = curr->next;
	}

	return dummy->next;
}

ListNode* partition(ListNode* head, int x) {

	ListNode* dummy1 = new ListNode(0);
	ListNode* dummy2 = new ListNode(0);

	ListNode* curr1 = dummy1;
	ListNode* curr2 = dummy2;

	while (head != NULL) {
		if (head->val < x) {
			curr1->next = head;
			curr1 = curr1->next;
		} else {
			curr2->next = head;
			curr2 = curr2->next;
		}

		head = head->next;
	}

	curr1->next = dummy2->next;
	curr2->next = NULL;
	return dummy1->next;
}

vector<int> nextLargerNodes(ListNode* head) {

	stack<pair<int, int> > s;
	vector<int> res(len(head), 0);
	// vector<int> name of vector(size of vector,data with which you want to initialize your vector)

	int idx = 0;

	while (head != NULL) {

		while (!s.empty() and s.top().first < head->val) {
			pair<int, int> data = s.top();
			s.pop();

			res[data.second] = head->val;
		}

		s.push({head->val, idx});
		idx++;
		head = head->next;
	}

	// no need because the vector is initialized with zero
	// while(!s.empty()){
	//     // fill there index with 0/-1
	// }

	return res;
}

int len(ListNode* head) {
	ListNode* temp = head;

	int count = 0;

	while (temp != NULL) {
		temp = temp->next;
		count++;
	}

	return count;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	int n = matrix.size();
	if (n == 0) return 0;

	int maxValue = 0;

	int m = matrix[0].size();
	vector<int> height(m, 0);

	for (int i = 0; i < n; i++) {
		// traversing the whole row (therefore all the columns)
		for (int j = 0; j < m; j++) {
			char ch = matrix[i][j];

			if (ch == '1') {
				height[j] += 1;
			} else {
				height[j] = 0;
			}
		}

		int areaForThisRow = histogramArea(height);
		maxValue = max(areaForThisRow, maxValue);
	}

	return maxValue;
}

int histogramArea(vector<int> height) {
	stack<int> s;
	int n = height.size();
	int maxArea = 0;

	int i = 0;

	while (i < n) {

		if (s.empty() or height[s.top()] <= height[i]) {
			s.push(i);
			i++;
		} else {

			int extractTop = s.top();
			s.pop();

			int ht = height[extractTop];

			int nextSmallerIndex = i;

			int currArea;

			if (s.empty()) {
				int width = nextSmallerIndex;
				currArea = width * ht;
			} else {
				int prevSmallerIndex = s.top();
				int width = nextSmallerIndex - prevSmallerIndex - 1;

				currArea = width * ht;
			}

			maxArea = max(maxArea, currArea);
		}
	}

	while (!s.empty()) {

		int extractTop = s.top();
		s.pop();

		int ht = height[extractTop];

		int nextSmallerIndex = i;

		int currArea;

		if (s.empty()) {
			int width = nextSmallerIndex;
			currArea = width * ht;
		} else {
			int prevSmallerIndex = s.top();
			int width = nextSmallerIndex - prevSmallerIndex - 1;

			currArea = width * ht;
		}

		maxArea = max(maxArea, currArea);
	}

	return maxArea;
}

int main() {


	return 0;
}