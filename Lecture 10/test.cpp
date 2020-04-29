#include <iostream>

using namespace std;

int simpleFunction(int a, int b) {
	return a + b;
}

int linearSearch(int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			return i;
		}
	}

	return -1;
}

void linearTimeComplexity(int arr[], int n) {
	// x
	for (int i = 0; i < n; i++) {
		int a = 8;
		int b = 7;
	}

	// y
	for (int i = 0; i < n / 2; i++) {
		int a = 67;
		int b = 90;
		int c = 12;
	}

	// x+ y
}

void nestedLoopTime(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
		{
			/* code */ // K iteration
		}
	}
}

// for(int i=1;i<=n;i++){
// 	// O(1)
// }
// 1 + 1 + 1 + 1 + 1 + 1 + ............n;

//O(const)/O(1)
int timeBatao(int n) {

	int ans  = 0;

	for (int i = 0; i < 256; i++) {
		ans += i;
	}

	return ans;
}

int fun(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 32; j++) {
			//Code
		}
	}
}

int main() {

	// int val = simpleFunction(10, 6);
	// cout << endl;

	int arr[] = {2, 4, 3, 5, 6, 7, 1};
	int n = 7;
	int key = 5;

	cout << linearSearch(arr, n, key) << endl;

	return 0;
}