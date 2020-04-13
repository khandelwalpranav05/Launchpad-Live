#include <iostream>

using namespace std;

int main() {

	int n = 5;

	int colSize = 1;

	int val = 1;

	for (int row = 1; row <= n; row++) {

		for (int col = 1; col <= colSize; col++) {
			cout << val << " ";

			// if (val < 9) {
			// 	val++;
			// } else {
			// 	val = 1;
			// }

			val++;

			if (val > 9) {
				val = 1;
			}
		}

		cout << endl;
		// cout << colSize << endl;

		//Done
		colSize = colSize * 2;
	}

	return 0;
}