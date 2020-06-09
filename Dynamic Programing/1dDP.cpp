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
int reduceToOne(int n) {
	// check1++;
	if (n == 1) {
		return 0;
	}

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if (n % 2 == 0) {
		count2 = reduceToOne(n / 2);
	}

	if (n % 3 == 0) {
		count3 = reduceToOne(n / 3);
	}

	count1 = reduceToOne(n - 1);

	int minValue = min(count1, min(count2, count3));

	minValue += 1;
	return minValue;
}


int check2 = 0;
int reduceToOneMemo(int n, int dp[]) {
	// check2++;
	if (n == 1) {
		dp[n] = 0;
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if (n % 2 == 0) {
		count2 = reduceToOneMemo(n / 2, dp);
	}

	if (n % 3 == 0) {
		count3 = reduceToOneMemo(n / 3, dp);
	}

	count1 = reduceToOneMemo(n - 1, dp);

	int minValue = min(count1, min(count2, count3));

	minValue += 1;

	dp[n] = minValue;

	for (int i = 1; i <= 10; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "******************" << endl;

	return minValue;
}

int reduceToOnePUREDP(int n) {

	int dp[n + 1];

	//base case
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 2; i <= n; i++) {
		// recursive case
		// reduceToOne(i); <- dp[i]

		int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

		if (i % 2 == 0) {
			count2 = dp[i / 2];
		}

		if (i % 3 == 0) {
			count3 = dp[i / 3];
		}

		count1 = dp[i - 1];

		int minValue = min(count1, min(count2, count3));
		minValue++;

		dp[i] = minValue;
	}

	return dp[n];
}

int countBoardPath(int start, int end) {
	check1++;
	if (start == end) {
		return 1;
	}

	if (start > end) {
		return 0;
	}

	int count = 0;

	for (int jump = 1; jump <= 6; jump++) {
		count += countBoardPath(start + jump, end);
	}

	return count;
}


int countBoardPathMemo(int start, int end, int dp[]) {
	check2++;
	if (start == end) {
		dp[start] = 1;
		return 1;
	}

	if (start > end) {
		return 0;
	}

	// check if the value for this given input/state already
	// exist in your dp or not
	if (dp[start] != -1) {
		return dp[start];
	}

	int count = 0;

	for (int jump = 1; jump <= 6; jump++) {
		count += countBoardPathMemo(start + jump, end, dp);
	}

	dp[start] = count; // before returning to your parent call
	// just store the answer of this input/state in your dp

	// for (int i = 0; i <= end; i++) {
	// 	cout << dp[i] << "\t";
	// }
	// cout << endl << "*******************" << endl;

	return count;
}

int countBoardPathPUREDP(int start, int end) {
	int dp[end + 1];

	// base case
	dp[end] = 1;

	for (int i = end - 1; i >= start; i--) {

		// recursive case
		int count = 0;

		for (int jump = 1; jump <= 6; jump++) {

			if (jump + i <= end) {
				count += dp[i + jump];
			} else {
				break;
			}
		}

		dp[i] = count;
	}

	return dp[start];
}

int main() {
	// int n = 10;

	// cout << reduceToOne(n) << endl;

	// int dp[n + 1];
	// memset(dp, -1, sizeof(dp));
	// cout << reduceToOneMemo(n, dp) << endl;

	// cout << "Number of function call for reduceToOne " << check1 << endl;
	// cout << "Number of function call for reduceToOneMemo " << check2 << endl;

	// cout << reduceToOnePUREDP(n) << endl;

	// int arr[5] = { -1};

	// for (int i = 0; i < 5; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	int start = 0;
	int end = 10;

	cout << countBoardPath(start, end);

	int dp[end + 1];
	memset(dp, -1, sizeof(dp));
	cout << countBoardPathMemo(start, end, dp) << endl;

	cout << "Number of function call for countBoardPath " << check1 << endl;
	cout << "Number of function call for countBoardPathMemo " << check2 << endl;


	// cout << countBoardPathPUREDP(start, end) << endl;

	return 0;
}