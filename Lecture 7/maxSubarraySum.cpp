#include <iostream>

using namespace std;

int main() {

	int arr[]  = { -1, -2, -3, -4};
	int n = 4;

	int maxSum = INT_MIN;
	for (int start = 0; start < n; start++) {

		for (int end = start; end < n; end++) {

			int sum = 0;
			// Iterating each subarray
			for (int k = start; k <= end; k++) {
				sum += arr[k]; //
				// cout << arr[k] << " ";
			}

			// cout << " -> Sum is " << sum << endl;
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}

	cout << "Max sum value is " << maxSum << endl;

	return 0;
}