#include <iostream>

using namespace std;

int main() {

	int arr[] = {15, 112, 13, 892, 41};
	int n = 5;

	int divider = 1;

	//Time: O(n^2) Worst Case
	while (divider < n) {

		for (int i = divider; i > 0; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
			} else {
				break;
			}
		}

		// cout << "********" << " At the " << divider << " iteration " << "***************" << endl;

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;

		// cout << "***********************" << endl;

		divider++;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}