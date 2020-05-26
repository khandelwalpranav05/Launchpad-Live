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

int main() {

	// cout << isBalanced("((()))(") << endl; // false
	// cout << isBalanced("(())()") << endl; // true
	// cout << isBalanced("((())") << endl; // false
	// cout << isBalanced("()()()") << endl; // true

	// cout << isDuplicate("((a+b))") << endl; // true
	// cout << isDuplicate("((a+b) + (c))") << endl; // false;

	int arr[] = {54, 5, 3, 6, 2, 10, 14};
	int n = 7;

	printNextGreater(arr, n);

	return 0;
}