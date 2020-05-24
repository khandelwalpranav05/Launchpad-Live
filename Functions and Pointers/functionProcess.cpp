#include <iostream>

using namespace std;

bool last(int nothing) {

	if (nothing == 6) {
		return true;
	} else {
		return false;
	}

}

void third() {
	cout << "You have reached to the start of third function" << endl;

	cout << "Value returned by last function is " << last(7) << endl;

	cout << "You have reached to the end of third function" << endl;
	// return;
}

int second(int x, int y) {
	cout << "You have reached to the start of second function" << endl;

	third();

	cout << "You have reached to the end of second function" << endl;
	return 5;

	// Nothing works here
	cout << "Hello" << endl;
	// Nothing works here
}

float first(int a, int b) {

	cout << "You have reached to the start of first function" << endl;

	int sum = a + b + 0.5; // 15.5

	int c = second(a, b);

	sum = sum + c; // 20.5

	cout << "You have reached to the end of first function" << endl;

	return sum;
}

int main() {

	float val = first(7, 8);

	// int a = 5;
	// int b = 5;

	// first(a, b);

	cout << "Total is " << val << endl;

	return 0;
}