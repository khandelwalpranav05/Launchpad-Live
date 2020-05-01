#include <iostream>

using namespace std;

int hulkProblem(int n) {

	int count = 0;

	while (n > 0) {

		int val = n & 1;

		count += val;

		n = n >> 1;
	}

	return count;
}

int uniqueNumber(int nums[], int n) {
	int val = 0;

	for (int i = 0; i < n; i++) {
		val = val ^ nums[i];
	}

	return val;
}

void uniqueNumberII(int arr[], int n) {

	int xorPair = 0;

	for (int i = 0; i < n; i++) {
		xorPair ^= arr[i];
	}

	int element = xorPair;

	int pos = 0;

	while (element > 0) {
		int temp = element & 1;

		if (temp) {
			break;
		}

		pos++;
		element = element >> 1;
	}

	int catagoryWithOnes = 0;

	for (int i = 0; i < n; i++) {

		int val = arr[i];

		int check = val >> pos;

		if (check & 1) {
			catagoryWithOnes = catagoryWithOnes ^ arr[i];
		}
	}

	int catagoryWithZero = catagoryWithOnes ^ xorPair;

	cout << catagoryWithOnes << endl;
	cout << catagoryWithZero << endl;
}

int main() {

	// cout << hulkProblem(9) << endl;

	// int n = 9;
	// cout << __builtin_popcount(n) << endl;

	int arr[] = {1, 2, 3, 4, 7, 9, 4, 3, 2, 1};
	int n = 10;

	uniqueNumberII(arr, n);

	return 0;
}