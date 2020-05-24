#include <iostream>
#include <vector>

using namespace std;


// TIME: O(sqrt(n))
bool isPrime(int n) {
	if (n == 1) return false;

	if (n == 2) return true;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}


// TIME: O()
void sieve(vector<int> &arr) {

	int n = arr.size() - 1;

	// all even values are not prime or all odd values are prime

	for (int i = 3; i <= n; i += 2) {
		arr[i] = 1;
	}

	for (int i = 3; i * i <= n; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= n; j = j + i) {
				arr[j] = 0;
			}
		}
	}

	// seperate case
	arr[2] = 1;
	arr[0] = 0;
	arr[1] = 0;
}

int main() {

	int n = 30;
	vector<int> arr(n + 1, 0);



	return 0;
}