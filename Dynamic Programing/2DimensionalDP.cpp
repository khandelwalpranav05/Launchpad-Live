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

int mazePath(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
	if (sr == er and sc == ec) {
		return 1;
	}

	if (sr > er or sc > ec) {
		return 0;
	}

	if (dp[sr][sc] != -1) {
		return dp[sr][sc];
	}

	int rightPath = mazePath(sr, sc + 1, er, ec, dp);
	int downPath = mazePath(sr + 1, sc, er, ec, dp);

	int totalPath = rightPath + downPath;

	dp[sr][sc] = totalPath;

	return totalPath;
}

int uniquePathsMemo(int m, int n) {

	int row = m;
	int col = n;
	vector<vector<int>> dp(row, vector<int> (col, -1));

	return mazePath(0, 0, m - 1, n - 1, dp);
}

int main() {


	return 0;
}