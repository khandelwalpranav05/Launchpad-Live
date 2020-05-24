#include <iostream>

using namespace std;

int main() {

	int arr[]  = { -1111, -1222, -1333, -1444};
	int n = 4;

	int maxSum = INT_MIN;

	// Time: O(n^2)
	for (int i = 0; i < n; i++) { // STARTing

		int sum = 0;

		for (int j = i; j < n; j++) { // ENDing

			sum += arr[j];

			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}

	cout << "Max sum value is " << maxSum << endl;

	return 0;
}