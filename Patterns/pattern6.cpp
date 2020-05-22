#include <iostream>

using namespace std;

int main() {

	int n = 5;

	for (int row = 1; row <= n; row++) {

		int noOfSpaces = n - row;
		int noOfStars = 2 * row - 1;

		for (int space = 1; space <= noOfSpaces; space++) {
			cout << " ";
		}

		for (int star = 1; star <= noOfStars; star++) {
			cout << "*";
		}

		cout << endl;
	}

	return 0;
}