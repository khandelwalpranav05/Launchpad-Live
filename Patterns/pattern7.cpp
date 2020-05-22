#include <iostream>

using namespace std;

int main() {

	int n = 5;

	cout << "1" << endl;

	for (int row = 2; row <= n; row++) {

		//Start
		cout << "1 ";

		//Zeros

		for (int midZeros = 1; midZeros <= row - 2; midZeros++) {
			cout << "0 ";
		}

		//END
		cout << "1 " << endl;
	}

	// cout << "* * * * * * * * * * * * * * * " << endl;

	// for (int i = 1; i <= 15; i++) {
	// 	cout << "* ";
	// }

	return 0;
}