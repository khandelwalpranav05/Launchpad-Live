#include <iostream>

using namespace std;

int main() {

	int n = 5;

	for (int row = 1; row <= n; row++) {

		//Spaces
		// n-row

		for (int pranav = 1; pranav <= n - row; pranav++) {
			cout << " ";
		}

		//INC 1 -> row
		for (int inc = 1; inc <= row; inc++) {
			cout << inc;
		}

		//DEC row-1 -> 1

		for (int dec = row - 1; dec >= 1; dec--) {
			cout << dec;
		}
		cout << endl;

	}

	return 0;
}