#include <iostream>

using namespace std;

void saySomething() {

	int a = 78;
	int b = 90;

	bool val = true;

	cout << "Inside the function" << endl;

	cout << "Value of a is " << a << endl;

	char ch = 'p';

	cout << ch << endl;

	// return; // Not mandatory
}

int main() {

	cout << "Before the function call" << endl;
	cout << a << endl;

	saySomething();

	cout << a << endl;
	cout << a << endl;

	cout << "After the function call" << endl;

	// int i = 0;

	// while () {

	// 	cout << i << endl;

	// }

	return 0;
}