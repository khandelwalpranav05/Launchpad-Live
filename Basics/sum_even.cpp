#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int sum = 0;

	// for (int x = 1; x <= n; x = x + 1) {
	// 	if (x % 2 == 0) { //EVEN
	// 		sum = sum + x;
	// 	}
	// }

	for (int x = 2; x <= n; x = x + 2) {
		sum = sum + x;
	}

	cout << "Sum of all even values till " << n << " is " << sum << endl;

	return 0;
}