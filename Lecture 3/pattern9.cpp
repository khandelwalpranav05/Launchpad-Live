#include <iostream>

using namespace std;

int main() {

	int n = 6;

	for (int row = 1; row <= n; row++) {

		// INC
		for (int inc = n - row + 1; inc <= n - 1; inc++) {
			cout << inc << " ";
		}

		// no of 5s
		for (int count = 1; count <= n - row + 1; count++) {
			cout << n << " ";
		}

		cout << endl;
	}

	return 0;
}