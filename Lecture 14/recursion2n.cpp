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
	int withZero = countBinaryString(n - 1);
	int withOne = countBinaryString(n - 2);

	int total = withZero + withOne;
	return total;
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
		return -1;
	}

	//RECURSIVE CASE
	int count = 0;

	for (int jump = 1; jump <= 6; jump++) {
		count += countBoardPath(start + jump, end);
	}

	return count;
}

int main() {

	// int arr[] = {3, 2, 3, 4, 5, 3, 6};
	// int n = 7;
	// int key = 3;

	// cout << lastIndex(0, arr, n, key) << endl;

	// int n = 6;
	// cout << fib(n) << endl;

	// cout << countBinaryString(3) << endl;

	cout << countBoardPath(0, 4) << endl;

	return 0;
}