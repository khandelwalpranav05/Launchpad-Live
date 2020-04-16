#include <iostream>

using namespace std;

int main() {

	int n = 5;

	int row;
	int col;

	for (row = 1; row <= n; row++) {

		// cout << "I'm at " << row << " row" << endl;

		for (col = 1; col <= row; col++) {
			cout << "* ";
		}
		cout << endl;

	}

	// cout << "* * * * * * * * * * * * * *. * *" << endl;

	// int n = 56;

	// for (int i = 1; i <= 56; i++) {
	// 	cout << "* ";
	// }

	return 0;
}