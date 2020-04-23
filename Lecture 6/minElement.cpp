#include <iostream>

using namespace std;

int main() {

	int arr[] = {4, 3, 6, 5, 2, 9};
	int n = 6;

	int minValue = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] < minValue) {
			minValue = arr[i];
		}
	}

	cout << "Min value inside this array is " << minValue << endl;

	return 0;
}