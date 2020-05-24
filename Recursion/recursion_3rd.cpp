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
	string ros = str.substr(1); // "23"

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

void printBoardPath(int start, int end, string ans) {
	//BASE CASE
	if (start == end) {
		cout << ans << endl;
		return;
	}

	if (start > end) {
		return;
	}

	// RECURSIVE CASE

	for (int jump = 1; jump <= 6; jump++) {

		string temp = to_string(jump);
		printBoardPath(start + jump, end, ans + temp);
	}
}

void printMazePath(int sr, int sc, int er, int ec, string ans) {
	// TODO
	// HOMEWORK
}

int reduceToOne(int n) {
	if (n == 1) {
		return 0;
	}

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if (n % 2 == 0) {
		count2 = reduceToOne(n / 2); //recursion
	}

	if (n % 3 == 0) {
		count3 = reduceToOne(n / 3); //recursion
	}

	count1 = reduceToOne(n - 1); //recursion

	int minOperation = min(count2, min(count1, count3));
	return minOperation + 1;
}

int main() {

	// printPermutations("abc", "");
	// printKeypad("	423", "");

	// 423
	// 4 -> "qwerty" (6)
	// 2 -> "abcd" (4)
	// 3 -> "efg" (3)

	// total = 6*4*3

	// printBoardPath(0, 10, "");

	// cout << reduceToOne(10) << endl;

	return 0;
}