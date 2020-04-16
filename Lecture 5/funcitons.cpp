#include <iostream>

using namespace std;

int factorial(float x) {
	int ans = 1;

	for (int i = 1; i <= x; ++i) {
		ans = ans * i;
	}

	return ans;
}

int main() {

	int n = 5;
	int r = 2;

	// int nfact = 1;

	// for (int i = 1; i <= n; i++) {
	// 	nfact = nfact * i;
	// }

	// int rfact = 1;

	// for (int i = 1; i <= r; i++) {
	// 	rfact = rfact * i;
	// }

	// int nrfact = 1;

	// for (int i = 1; i <= (n - r); i++) {
	// 	nrfact = nrfact * i;
	//

	int nfact = factorial(n);
	int rfact = factorial(r);
	int nrfact = factorial(n - r);

	cout << "nfact " << nfact << endl;
	cout << "rfact " << rfact << endl;
	cout << "nrfact " << nrfact << endl;


	// int result = nfact / (rfact * nrfact);

	// cout << "Result is " << result << endl;

	return 0;
}

