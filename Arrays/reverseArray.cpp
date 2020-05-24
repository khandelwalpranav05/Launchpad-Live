#include <iostream>

using namespace std;

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;

	int left = 0;
	int right = n - 1;

	//Time: O(n)
	while (left < right) {
		swap(arr[left], arr[right]);
		left++;
		right--;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// swap(arr[1], arr[4]);

	// // int temp = arr[4];
	// // arr[4] = arr[1];
	// // arr[1] = temp;

	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	// int x = 10;
	// int y = 20;

	// int temp = x;
	// x = y;
	// y = temp;

	// cout << "X " << x << endl;
	// cout << "Y " << y << endl;

	return 0;
}