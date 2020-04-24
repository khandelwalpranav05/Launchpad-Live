#include <iostream>

using namespace std;

int distinctRectange(int arr[], int n, int k) {

	int left = 0;
	int right = n - 1;

	int count = 0;

	while (left <= right) {

		if (arr[left]*arr[right] < k) {
			count = count + (right - left) * 2 + 1;
			left++;

		} else {
			right--;
		}
	}

	return count;
}

int targetSumPair(int arr[], int n, int target) {

	int left = 0;
	int right = n - 1;

	int count = 0;

	while (left < right) {

		if (arr[left] + arr[right] > target) {
			right--;
		} else if (arr[left] + arr[right] < target) {
			left++;
		} else {
			count++;
			left++;
			right--;
		}
	}

	return count;
}

int main() {

	// int arr[] = {2, 3, 4, 5};
	// int n = 4;

	// int k = 15;

	// cout << distinctRectange(arr, n, k) << endl;

	// int arr[] = {0, 1, 2, 3, 4, 6, 7, 8, 9} ;
	// int n = 9;
	// int target = 7;

	// cout << targetSumPair(arr, n, target) << endl;

	int arr[] = {14, 12, 31};

	for (int i = 0; i < ; i++) {

	}

	for () {

	}

	for () {
		for () {
			//NOT VALID
		}
	}

	return 0;
}