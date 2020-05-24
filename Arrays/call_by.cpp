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

void check(int k) {
	k = k + 1;

	cout << "In the function" << endl;
	cout << "Value of a is " << k << endl; // 11
	cout << "Address of a is " << &k << endl; // different from line 35
	cout << "**************************" << endl;
}

int main() {

	int a = 10;

	check(a);
	cout << "In the Main" << endl;
	cout << "Value of a is " << a << endl; // 10
	cout << "Address of a is " << &a << endl; // different from line 23
	cout << "***************************" << endl;

	return 0;
}