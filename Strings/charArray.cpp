#include <iostream>

using namespace std;

int main() {

	// char arr[] = {'a', 'b', 'c', '\0'};

	// char brr[] = {'x', 'y', 'z', '\0'};

	// // int crr[] = {3, 4, 5};

	// char prr[] = {'p', 'q', 'r', 's'};
	// char str[] = "pqrs"; // it includes '\0' by the end

	// // cout << crr << endl; // address of arr

	// // cout << arr << endl;
	// // cout << brr << endl;
	// // cout << prr << endl;
	// // cout << str << endl;

	// cout << sizeof(prr) << endl; // 4
	// cout << sizeof(str) << endl; // 5


	char arr[2];
	// for (int i = 0; i < 17; i++) {
	// 	cin >> arr[i];
	// }
	// cout << arr << endl;

	cin >> arr;
	cout << arr << endl;
	cout << sizeof(arr) << endl;

	return 0;
}