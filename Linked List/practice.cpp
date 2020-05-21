#include <iostream>

using namespace std;

void check(int* &aptr) {
	aptr = aptr + 1;
}

int main() {

	int x = 10;

	int* aptr = &x; // 4K
	cout << aptr << endl;

	check(aptr);

	cout << aptr << endl; // 4K / 8K

	return 0;
}