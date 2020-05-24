#include <iostream>

using namespace std;

// Space: O(1)
int constantSpace(int n) {
	int a = n;
	int b;
	int c;
	int y;
	return a + n;
}

int main() {

	int n = 385;
	cout << constantSpace(n) << endl;

	return 0;
}