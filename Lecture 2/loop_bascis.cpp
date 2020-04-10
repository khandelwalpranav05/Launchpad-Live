#include <iostream>

using namespace std;

int main() {

	int pos = 12; //starting

	while (pos < 10) { //ending or condition

		cout << "At position " << pos << endl;

		pos = pos + 1; // updation
	}

	if (pos == 10) {
		cout << "Reached" << endl;
	}

	return 0;
}