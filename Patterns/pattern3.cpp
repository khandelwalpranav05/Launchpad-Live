#include <iostream>

using namespace std;

int main() {

	int n = 4;

	int val = 1;

	for (int row = 1; row <= n; row++) {

		for (int col = 1; col <= row; col++) {
			cout << val << " ";
			val = val + 1;
			// val++;
		}
		cout << endl;
	}

	return 0;
}