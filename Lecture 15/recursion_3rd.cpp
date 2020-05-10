#include <iostream>

using namespace std;

void printPermutations(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	// abc
	// a < - bc
	// b < - ac
	// c < - ab

	for (int i = 0; i < str.length(); i++) {

		char ch = str[i];
		string ros = str.substr(0, i) + str.substr(i + 1);

		printPermutations(ros, ros + ch);
	}

}

string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(string str, string ans) {

}

int main() {

	// printPermutations("abc", "");
	printKeypad("23", "");

	return 0;
}