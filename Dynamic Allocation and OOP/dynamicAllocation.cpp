#include <iostream>
#include <vector>

using namespace std;

int main() {

	// variables
	// static allocation
	int a = 10;
	// int arr[10];

	// char ch;

	// dynamic allocation
	// new -> data is allocated inside the heap memory
	int* b = new int(10);


	// Arrays

	// static allocation
	int arr[5];

	// dynamic allocation

	// cout << "Please enter the size of the array" << endl;
	// int n;
	// cin >> n;

	int n = 5;
	int *brr = new int[n];

	// char *crr = new char[10];
	// char chrr[17];

	// cout << sizeof(chrr) << endl;
	// cout << sizeof(crr) << endl;

	// for (int i = 0; i < n; i++) {
	// 	brr[i] = i + 1;
	// }

	// for (int i = 0; i < n; i++) {
	// 	cout << brr[i] << " ";
	// }
	// cout << endl;

	// cout << sizeof(arr) << endl;
	// cout << sizeof(brr) << endl;

	delete b;
	delete [] brr;

	return 0;
}