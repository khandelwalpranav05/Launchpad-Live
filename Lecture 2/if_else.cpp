#include <iostream>

using namespace std;

int main() {

	int n = 27;

	// Divisible by 2 or 3

	// condition
	// if (n % 2 == 0) {
	// 	cout << "It is Divisible by 2" << endl;
	// } else {
	// 	cout << "It is Divisible by 3" << endl;
	// }

	// if (n % 2 == 0) {
	// 	cout << "It is Divisible by 2" << endl;
	// }


	// if (n % 3 == 0) {
	// 	cout << "It is Divisible by 3" << endl;
	// } else {
	// 	cout << "Not Divisible" << endl;
	// }

	if (n % 2 == 0 && n % 3 == 0) {
		cout << "It is Divisible by 2 and It is Divisible by 3" << endl;
	} else if (n % 2 == 0) {
		cout << "It is Divisible by 2" << endl;
	} else if (n % 3 == 0) {
		cout << "It is Divisible by 3" << endl;
	} else {
		cout << "Not Divisible" << endl;
	}

	// int wind = 0;
	// int friends = 0;

	// if (wind == 0) {
	// 	cout << "can't play" << endl;
	// } else {
	// 	if (friends > 0) {
	// 		cout << "Can play" << endl;
	// 	} else {
	// 		cout << "Can't play" << endl;
	// 	}
	// }

	return 0;
}