#include <iostream>

using namespace std;

int main() {

	int arr[] = {15, 41, 13, 892, 112};
	int n = 5;

	int minIndex = 0;

	// Time:O(n^2)
	while (minIndex < n - 1) {

		int minVal = arr[minIndex];

		int replaceIdx = minIndex;

		for (int i = minIndex + 1; i < n; i++) {
			if (arr[i] < minVal) {
				replaceIdx = i;
				minVal = arr[i];
			}
		}

		swap(arr[minIndex], arr[replaceIdx]);

		minIndex++;


		// cout << "********" << " At the " << minIndex << " iteration " << "***************" << endl;

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;

		// cout << "***********************" << endl;

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}