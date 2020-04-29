#include <iostream>

using namespace std;

int main() {

	int arr[] = {15, 112, 13, 892, 41};
	int n = 5;

	int counter = 1;

	//Tiem:O(n^2)
	while (counter < n) {

		for (int i = 0; i < n - counter; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}

		// cout << "********" << " At the " << counter << " iteration " << "***************" << endl;

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;

		// cout << "***********************" << endl;

		counter++;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}