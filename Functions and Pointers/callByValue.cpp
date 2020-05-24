#include <iostream>

using namespace std;

// int pranav(int a) {
// 	cout << "inside pranav value of a " << a << endl;
// }

void check(int a) {
	cout << a << endl;
	a = 46;
	cout << "Value of a inside function " << a << endl;

	a++;

	// return 78;
}

int main() { // start

	int a = 10;
	check(a);

	cout << "Value of a inside main " << a << endl;

	return 0; // end (acknowledgment)
}