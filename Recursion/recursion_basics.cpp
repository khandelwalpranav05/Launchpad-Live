#include <iostream>

using namespace std;

//Time:O(n)
// Space : O(n)
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


//Time: O(n)
//Space: O(n)
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

//Time: O(n)
//Space: O(n)
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

//Time:O(n)
// Space : O(n)
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

//Time: O(n)
//Space: O(n)
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

//Time: O(n)
//Space: O(n)
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
	//BASE CASE
	if (si == n - 1 or n == 0) {
		return true;
	}

	//RECURSIVE CASE
	bool isSubproblemSorted = isSorted(si + 1, arr, n);

	if (arr[si] <= arr[si + 1] and isSubproblemSorted) {
		return true;
	} else {
		return false;
	}

	//RECURSIVE CASE
	// if (arr[si] > arr[si + 1]) {
	// 	return false;

	// } else {
	// 	// check for the rest of the array
	// 	bool isSubproblemSorted = isSorted(si + 1, arr, n);
	// 	// if (isSubproblemSorted) {
	// 	// 	return true;
	// 	// } else {
	// 	// 	return false;
	// 	// }
	// 	return isSubproblemSorted;
	// }
}

//Time: O(log(p))
//Space: O(log(p))
int powerBetter(int n, int p) {
	if (p == 0) {
		return 1;
	}

	int subProblem = powerBetter(n, p / 2);

	if (p & 1) {
		int ans = subProblem * subProblem * n;
		return ans;
	} else {
		int ans = subProblem * subProblem;
		return ans;
	}
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

	// int arr[] = {1, 2, 3, 4, 5, 6};
	// int n = 6;
	// int si = 0;

	// cout << isSorted(si, arr, n) << endl;

	// cout << powerBetter(2, 6) << endl;


	return 0;
}