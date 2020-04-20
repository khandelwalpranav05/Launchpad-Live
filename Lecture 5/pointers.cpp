#include <iostream>

using namespace std;

int main() {

	// int x = 10;
	// int* xptr = &x;

	// // cout << (&x) << endl;
	// // cout << xptr << endl;

	// cout << "Values " << endl;
	// cout << x << endl;
	// cout << (*xptr) << endl;

	// cout << "Increment 1 to x" << endl;

	// x++;

	// cout << (*xptr) << endl;

	// cout << "Increment 1 to *xptr" << endl;

	// *xptr = *xptr + 1;

	// cout << x << endl;

	// cout << "Size of data types" << endl;

	// cout << sizeof(int) << endl; // 4
	// cout << sizeof(char) << endl; // 1
	// cout << sizeof(bool) << endl; // 1
	// cout << sizeof(float) << endl; // 4

	// cout << "Size of pointers" << endl;

	// cout << sizeof(int*) << endl; // 8
	// cout << sizeof(char*) << endl; // 8
	// cout << sizeof(bool*) << endl; // 8
	// cout << sizeof(float*) << endl; // 8

	// float y = 10.56;
	// float* yptr = &y;

	// cout << y << endl;
	// cout << (*yptr) << endl;

	// int x =
	// bool n =
	// char p =
	// float f =

	// int*
	// float*
	// char*
	// bool*

	// bool val = true;

	// cout << (&val) << endl;

	// int x = 10;
	// char* cptr = &x;

	// int x = 10;
	// float* fptr = &x;

	// cout << sizeof(int****) << endl;

	int x = 10;

	int &z = x;
	int &y = x;

	x++;

	// cout << z << endl; // 11

	y++;

	// cout << z << endl;

	cout << (&x) << endl;
	cout << (&y) << endl;
	cout << (&z) << endl;

	return 0;
}