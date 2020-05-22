#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

void check(int* k) {
	*k = *k + 1;
	//a = a + 1

	// cout << "In the function" << endl;
	// cout << "Value of k is " << k << endl; // SAME
	cout << "Address of k is " << &k << endl;
	// cout << "**************************" << endl;
}

int main() {

	int a = 10;

	check(&a);

	// cout << a << endl;
	// cout << "In the Main" << endl;
	// cout << "Value of a is " << a << endl;
	cout << "Address of a is " << &a << endl; //SAME
	// cout << "***************************" << endl;

	return 0;
}