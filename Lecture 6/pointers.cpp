#include <iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr;
	xptr = &x;

	// cout << (&x) << endl; // 4k
	// cout << xptr << endl; // 4k

	// cout << *(&x) << endl; // 10
	// cout << *(xptr) << endl; // 10

	// cout << *(&xptr) << endl; // 4k
	// cout << &(*xptr) << endl; // 4k

	cout << xptr << endl; // 4K
	cout << (xptr + 1) << endl;

	return 0;
}