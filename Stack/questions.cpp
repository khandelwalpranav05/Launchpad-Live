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

}

int main() {

	cout << isBalanced("((()))(") << endl; // false
	cout << isBalanced("(())()") << endl; // true
	cout << isBalanced("((())") << endl; // false
	cout << isBalanced("()()()") << endl; // true

	return 0;
}