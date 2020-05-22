#include <iostream>

using namespace std;

int main() {

	// int n = 5;
	int n; // mandatory
	cout << "Enter n" << endl; // not mandatory
	cin >> n; //6 //8 //5684; // mandatory

	cout << "n is now " << n << endl; // not mandatory

	int sum = 0;

	int x = 1;

	while (x <= n) { //ending
		sum = sum + x;
		x = x + 1;
	}

	cout << "Total is " << sum << endl;

	return 0;
}