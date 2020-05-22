#include <iostream>

using namespace std;

int main() {

	int arr[] = { -2, 2, 5, -11, 16};
	int n = 5;

	int maxSum = arr[0];
	int currSum = arr[0];

	//Time: O(n)
	for (int i = 1; i < n; i++) {

		int continueWithSubarray = currSum + arr[i];
		int startNewSubarray = arr[i];

		currSum = max(startNewSubarray, continueWithSubarray);

		if (currSum > maxSum) {
			maxSum = currSum;
		}
	}

	cout << "Max subarray sum value is " << maxSum << endl;

	return 0;
}