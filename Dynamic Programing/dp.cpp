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

int check1 = 0;

int fib(int n) {
	check1++;
	if (n == 0 or n == 1) {
		return n;
	}

	int fibn1 = fib(n - 1);
	int fibn2 = fib(n - 2);

	int fibn = fibn1 + fibn2;
	return fibn;
}

int check2 = 0;

int fibMemo(int n, int dp[]) {
	check2++;
	if (n == 0 or n == 1) {
		// base case
		// update my dp for my base cases as well
		dp[n] = n;
		return n;
	}

	// if you've already computed the nth value in your dp
	if (dp[n] != -1) {
		return dp[n];
	}

	int fibn1 = fibMemo(n - 1, dp);
	int fibn2 = fibMemo(n - 2, dp);

	int fibn = fibn1 + fibn2;

	dp[n] = fibn; // store your value in dp

	for (int i = 0; i <= 5; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "*******************" << endl;

	return fibn;
}

int fibPUREDP(int n) {

	int dp[n + 1];

	// base case
	dp[0] = 0;
	dp[1] = 1;

	// f(0) -> 0;
	// f(1) -> 1;

	for (int i = 2; i <= n; i++) {

		// f(i) = f(i - 1) + f(i - 2);

		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {

	int n = 5;
	// cout << fib(n) << endl;

	// int dp[n + 1];
	// memset(dp, -1, sizeof(dp)); // fill your whole dp array with -1
	// cout << fibMemo(n, dp) << endl;

	// cout << "Number of function call for fib " << check1 << endl;
	// cout << "Number of function call for fibMemo " << check2 << endl;

	cout << fibPUREDP(n) << endl;

	return 0;
}