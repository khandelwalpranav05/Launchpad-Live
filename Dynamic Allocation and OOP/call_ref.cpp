#include <iostream>

using namespace std;

void second(int &another) {
	another++;
}

void check(int &ref) {
	ref++;
	second(ref);
}

int main() {

	int a = 10;
	check(a);

	cout << "Value of inside Main " << a << endl;

	// int z = 10;
	// int &x = z;
	// x++;

	// cout << z << endl;

	return 0;
}

// void check(int *aptr) {
// 	*aptr = *aptr + 1;
// 	// a =   a  +   1 <- original visualization of the above exporession
// 	// 10 = 10  +   1
// }

// int main() {

// 	int a = 10;
// 	check(&a);

// 	cout << "Value of inside Main " << a << endl;

// 	return 0;
// }