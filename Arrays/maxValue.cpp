#include <iostream>

using namespace std;

int main() {

	int arr[] = {2, 4, 56, 8, 2, 90};
	int n = 6;

	int maxVal = arr[0];

	// Time: O(n)
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}

	cout << "Max value inside this array is " << maxVal << endl;

	return 0;
}