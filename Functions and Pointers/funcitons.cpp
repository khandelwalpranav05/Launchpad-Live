#include <iostream>

using namespace std;

int factorial(int x) {
	cout << "Function is called" << endl;
	int ans = 1;

	for (int i = 1; i <= x; ++i) {
		ans = ans * i;
	}

	// cout << ans << endl;

	return ans;
}

int main() {

	// cout << n << endl;

	int n = 5;
	int r = 2;

	// Calling a function (in case of void function only call this)
	factorial(n);

	// Calling a function and then printing the returned value
	cout << factorial(n) << endl; // 120

	// Calling a function and then storing the returned value
	int getValue = factorial(n);
	cout << "Get value " << getValue << endl;


	// cout << factorial(r) << endl; // 2
	// cout << factorial(n - r) << endl; // 6


	// int nfact = factorial(n);
	// int rfact = factorial(r);
	// int nrfact = factorial(n - r);

	// cout << "nfact " << nfact << endl;
	// cout << "rfact " << rfact << endl;
	// cout << "nrfact " << nrfact << endl;


	// int result = nfact / (rfact * nrfact);

	// cout << "Result is " << result << endl;

	return 0;
}



