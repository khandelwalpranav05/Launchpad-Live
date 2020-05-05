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
	// BASE CASE
	if (n == 0) {
		return;
	}

	// RECURSIVE CASE
	cout << n << endl;
	printDecreasing(n - 1);
	// return;
}

int power(int n, int p) {
	//Base
	if (p == 0) {
		return 1;
	}

	//Recursive Case
	int subProblem = power(n, p - 1);
	int ans = n * subProblem;
	return ans;
}
/*
	void function(int parameter) {
		// BASE CASE (smallest subproblem situation)
		// will always be the first check priority

		// WORK DONE HERE (BEFORE THE RECURSION CALL) while we are moving
		// up in the call stack

		function(subproblem); // Recursion CALL

		// WORK DONE HERE (AFTER THE RECURSION CALL) while we are moving
		// down in the call stack
	}
*/

int sumTillN(int n) {
	//BASE CASE
	if (n == 0) {
		return 0;
	}

	//RECURSIVE CASE
	int subproblem = sumTillN(n - 1);
	int ans = n + subproblem;
	return ans;
}

void printDecreasingIncreasing(int n) {
	if (n == 0) {
		return;
	}
	// if (n == 1) {
	// 	cout << 1 << endl;
	// 	cout << 1 << endl;
	// 	return;
	// }

	cout << n << endl;
	printDecreasingIncreasing(n - 1);
	cout << n << endl;
}

void printDecreasingODDIncreasingEVEN(int n) {
	if (n == 0) {
		return;
	}

	if (n & 1) { //ODD
		cout << n << endl; // printing all the decreasing values
	}

	printDecreasingODDIncreasingEVEN(n - 1);

	if ((n & 1) == 0) { //EVEN
		cout << n << endl; // printing all the increasing values
	}
}

int linearSearch(int si, int arr[], int n, int key) {
	// BASE CASE
	if (si == n) {
		return -1;
	}

	// RECURSIVE CASE
	if (arr[si] == key) {
		return si;
	} else {
		int index = linearSearch(si + 1, arr, n, key); // LS on rest of the array
		return index;
	}
}

bool isSorted(int si, int arr[], int n) {

}

int main() {

	// cout << factorial(5) << endl;

	// printIncreasing(5);

	// printDecreasing(5);

	// cout << power(2, 6) << endl;
	// cout << power(2, 0) << endl;

	// printDecreasingIncreasing(5);
	// printDecreasingODDIncreasingEVEN(5);

	// int arr[] = {3, 2, 4, 1, 5, 61, 7};
	// int n = 7;
	// int key = 61;
	// int si = 0;

	// cout << linearSearch(si, arr, n, key) << endl;

	return 0;
}