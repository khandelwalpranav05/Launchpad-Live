#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string str) {
	// intuition -> to find the most recent opening bracket in order to
	// match it with the current closing bracket (what DS we can use which
	// that helps us to find the most recent value/bracket)

	stack<char> s;

	for (int i = 0; i < str.length(); i++) {

		char ch = str[i];

		if (ch == '(') {
			s.push(ch);
		} else {

			// if you're here that means you have a closing
			// bracket

			if (s.empty()) {
				return false;
			}

			s.pop();
		}
	}

	// if (s.empty()) {
	// 	return true;
	// }

	// return false;
	return s.empty();
}

bool isDuplicate(string str) {

	stack<char> s;

	for (int i = 0; i < str.length(); i++) {

		char ch = str[i];

		if (ch != ')') {
			s.push(ch);
		} else {

			if (s.top() == '(') {
				return true;
			}

			while (s.top() != '(') {
				s.pop();
			}
			s.pop();
		}
	}

	return false;
}

void printNextGreater(int arr[], int n) {

	stack<int> s;

	for (int i = 0; i < n; i++) {

		while (!s.empty() and s.top() < arr[i]) {
			int val = s.top();
			s.pop();

			cout << val << " -> " << arr[i] << endl;
		}

		// my work is done
		// then just add me to the stack
		s.push(arr[i]);
	}

	while (!s.empty()) {
		int val = s.top();
		s.pop();

		cout << val << " -> -1" << endl;
	}

}

void stockSpan(int arr[], int n) {

	stack<int> s;

	for (int i = 0; i < n; i++) {

		while (!s.empty() and arr[s.top()] < arr[i]) {
			s.pop();
		}

		int days;
		if (!s.empty()) {
			days = i - s.top();
		} else {
			days = i + 1;
		}

		cout << arr[i] << " -> " << days << endl;
		s.push(i);
	}
}

void nextSmaller(int arr[], int n) {

	int ans[n];

	stack<int> s;

	for (int i = 0; i < n; i++) {

		while (!s.empty() and arr[s.top()] > arr[i]) {
			int idx = s.top();
			s.pop();

			ans[idx] = arr[i]; // assigning my value as next smaller to the
			// index of current element
		}
		s.push(i);
	}

	while (!s.empty()) {
		int idx = s.top();
		s.pop();

		ans[idx] = -1;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int histogramArea(int arr[], int n) {

	stack<int> s;

	int maxArea = 0;

	int i = 0;

	while (i < n) {

		if (s.empty() or arr[s.top()] <= arr[i]) {
			s.push(i);
			i++;
		} else {

			// if you're here means your ith index value is acting as a
			// next smaller for the current stack top element

			int extractTop = s.top();
			s.pop();

			int height = arr[extractTop];

			int nextSmallerIndex = i;

			int currArea;

			if (s.empty()) {
				int width = nextSmallerIndex;
				currArea = width * height;
			} else {
				int prevSmallerIndex = s.top();
				int width = nextSmallerIndex - prevSmallerIndex - 1;

				currArea = width * height;
			}

			maxArea = max(maxArea, currArea);
		}
	}


	// now when your i reaches to the last index(n)
	// now you will consider the nth bar as a 0 height bar
	// so that it could act as next smaller element for the
	// remaining values in my stack

	while (!s.empty()) {

		int extractTop = s.top();
		s.pop();

		int height = arr[extractTop];

		int nextSmallerIndex = i;

		int currArea;

		if (s.empty()) {
			int width = nextSmallerIndex;
			currArea = width * height;
		} else {
			int prevSmallerIndex = s.top();
			int width = nextSmallerIndex - prevSmallerIndex - 1;

			currArea = width * height;
		}

		maxArea = max(maxArea, currArea);
	}

	return maxArea;
}

int main() {

	// cout << isBalanced("((()))(") << endl; // false
	// cout << isBalanced("(())()") << endl; // true
	// cout << isBalanced("((())") << endl; // false
	// cout << isBalanced("()()()") << endl; // true

	// cout << isDuplicate("((a+b))") << endl; // true
	// cout << isDuplicate("((a+b) + (c))") << endl; // false;

	// int arr[] = {54, 5, 3, 6, 2, 10, 14};
	// int n = 7;

	// printNextGreater(arr, n);

	// int arr[] = {100, 80, 60, 70, 60, 75, 85};
	// int n = 7;

	// stockSpan(arr, n);

	// int arr[] = {2, 3, 1, 4, 6, 5, 0};
	// int n = 7;

	// nextSmaller(arr, n);

	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	int n = 7;

	cout << histogramArea(arr, n) << endl;

	return 0;
}