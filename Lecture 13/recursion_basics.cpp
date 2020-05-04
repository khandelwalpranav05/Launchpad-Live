#include <iostream>

using namespace std;

int factorial(int n) {
	// BASE CASE
	if (n == 0) {
		return 1;
	}

	// RECURSIVE
	int subProblem = factorial(n - 1);
	int ans = subProblem * n;
	return ans;
}

void printIncreasing(int n) {
	//Base Case
	if (n == 1) {
		// cout << 1 << endl;
		cout << n << endl;
		return;
	}

	// Recursive Case
	printIncreasing(n - 1);
	cout << n << endl;
	// return;
}

void printDecreasing(int n) {
	// RECURSIVE CASE
	cout << n << endl;
	printDecreasing(n - 1);
	// return;

	// BASE CASE
	if (n == 0) {
		return;
	}
}

int main() {

	// cout << factorial(5) << endl;

	// printIncreasing(5);

	printDecreasing(5);

	return 0;
}