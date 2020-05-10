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
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	// ch -> 4
	int idx = ch - '0';
	string key = code[idx]; // "ghi"

	for (int i = 0; i < key.length(); i++) {
		printKeypad(ros, ans + key[i]);
	}

	// recursion("23","g")
	// recursion("23","h")
	// recursion("23","i")
}

void printBoardPath(int start, int end, string path) {

}

int main() {

	// printPermutations("abc", "");
	// printKeypad("423", "");

	// 423
	// 4 -> "qwerty" (6)
	// 2 -> "abcd" (4)
	// 3 -> "efg" (3)

	// total = 6*4*3

	return 0;
}