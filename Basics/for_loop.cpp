#include <iostream>

using namespace std;

int main() {

	int x = 1;

	cout << "While Loop***********" << endl;

	while (x < 10) {
		x = x + 1;
		cout << "At " << x << endl;
	}

	cout << "For Loop***********" << endl;

	for (x = 1; x < 5; x = x + 1) {
		cout << "At " << x << endl;
	}

	return 0;
}