#include <iostream>

using namespace std;

int lastIndex(int si, int arr[], int n, int key) {
	//BASE CASE
	if (si == n) {
		return -1;
	}

	//RECURSIVE CASE
	int index = lastIndex(si + 1, arr, n, key);

	if (index != -1) {
		return index;
	} else {
		if (arr[si] == key) {
			return si;
		} else {
			return -1;
		}
	}
}

//Time: O(2^n)
//Space: O(n)
int fib(int n) {
	//BASE CASE
	// if (n == 0) {
	// 	return 0;
	// }
	// if (n == 1) {
	// 	return 1;
	// }

	if (n == 0 or n == 1) {
		return n;
	}

	//RECURSIVE CASE
	int fibn1 = fib(n - 1); // leftCALL
	int fibn2 = fib(n - 2); // rightCALL

	int fibn = fibn1 + fibn2;
	return fibn;
}

int countBinaryString(int n) {
	if (n == 1 or n == 2) {
		return n + 1;
	}

	//RECURSIVE CASE
	// int withZero = countBinaryString(n - 1);
	// int withOne = countBinaryString(n - 2);

	// int total = withZero + withOne;
	// return total;
	return countBinaryString(n - 1) + countBinaryString(n - 2);
}

int pairingProblem(int n) {
	//TODO
	//HOMEWORK
	return 0;
}

int countBoardPath(int start, int end) {
	if (start == end) {
		return 1;
	}

	if (start > end) {
		return 0;
	}

	//RECURSIVE CASE
	int count = 0;

	for (int jump = 1; jump <= 6; jump++) {
		count += countBoardPath(start + jump, end);
	}

	// // start = 5

	// countBoardPath(start + 1, end);
	// countBoardPath(start + 2, end);
	// countBoardPath(start + 3, end);
	// countBoardPath(start + 4, end);
	// countBoardPath(start + 5, end);
	// countBoardPath(start + 6, end);


	return count;
}

int countMazePath(int sr, int sc, int er, int ec) {
	//BASE CASE
	if (sr == er && sc == ec) {
		return 1;
	}

	if (sr > er or sc > ec) {
		return 0;
	}

	//RECURSIVE CASE
	int rightMove = countMazePath(sr, sc + 1, er, ec);
	int downMove = countMazePath(sr + 1, sc, er, ec);

	int total = rightMove + downMove;
	return total;
}

string addStar(string str) {
	if (str.length() == 0) {
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1); // subproblem

	//recursion call
	string recursionResult = addStar(ros);

	// my work

	if (ch == recursionResult[0]) {
		return ch + (string)"*" + recursionResult;
	} else {
		return ch + recursionResult;
	}
}

string removeDuplicate(string str) {
	if (str.length() == 0) {
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = removeDuplicate(ros);

	if (ch == recursionResult[0]) {
		return recursionResult;
	} else {
		return ch + recursionResult;
	}
}

string moveToEnd(string str) {

}

int main() {

	// int arr[] = {3, 2, 3, 4, 5, 3, 6};
	// int n = 7;
	// int key = 3;

	// cout << lastIndex(0, arr, n, key) << endl;

	// int n = 6;
	// cout << fib(n) << endl;

	// cout << countBinaryString(3) << endl;

	// cout << countBoardPath(0, 4) << endl;

	// cout << countMazePath(0, 0, 2, 2) << endl;

	// cout << addStar("abbcdde") << endl;

	// cout << removeDuplicate("abbccdde") << endl;

	return 0;
}