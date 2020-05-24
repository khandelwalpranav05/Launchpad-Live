#include <iostream>

using namespace std;

int main() {

	int arr[] = { 2, -2, -5, 11, -16};
	int n = 5;

	int minSum = arr[0];
	int currSum = arr[0];

	for (int i = 1; i < n; i++) {

		int continueWithSubarray = currSum + arr[i];
		int startNewSubarray = arr[i];

		currSum = min(startNewSubarray, continueWithSubarray);

		// if (currSum < minSum) {
		// 	minSum = currSum;
		// }

		minSum = min(currSum, minSum);
	}

	cout << "Min subarray sum value is " << minSum << endl;

	return 0;
}