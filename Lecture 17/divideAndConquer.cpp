#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (arr[mid] == key) {
			return mid;
		} else if (arr[mid] > key) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return -1;
}

int main() {

	int arr[] = {12, 23, 31, 45, 57, 69, 73, 82};
	int n = 8;
	int key = 731;

	cout << binarySearch(arr, n, key) << endl;

	return 0;
}