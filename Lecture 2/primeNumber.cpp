#include <iostream>

using namespace std;

int main() {

	int n = 29;

	int i;

	if (n == 2) {
		cout << "Prime" << endl;
	}

	for (i = 2; i < n; i = i + 1) {
		if (n % i == 0) {
			cout << "Not Prime" << endl;
			break;
		}
	}

	// <- AFTER THE LOOP HAS ENDED;
	if (i == n) {
		cout << "Prime" << endl;
	}

	// i < n
	// i <= n - 1

	return 0;
}