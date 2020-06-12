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

int mazePath(int sr, int sc, int er, int ec, vector<vector<int> > &dp) {
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
	vector<vector<int> > dp(row, vector<int> (col, -1));

	return mazePath(0, 0, m - 1, n - 1, dp);
}


int helper(int i, string &s1, int j, string &s2, vector<vector<int> > &dp) {
	// BASE CASE
	if (i == s1.length() or j == s2.length()) {
		dp[i][j] = 0;
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// RECURSIVE CASE
	int result;

	if (s1[i] == s2[j]) {
		result = helper(i + 1, s1, j + 1, s2, dp) + 1;
	} else {
		int first = helper(i + 1, s1, j, s2, dp);
		int second = helper(i, s1, j + 1, s2, dp);

		result = max(first, second);
	}

	dp[i][j] = result;

	for (int x = 0; x <= s1.length(); x++) {
		for (int y = 0; y <= s2.length(); y++) {
			cout << dp[x][y] << "\t";
		}
		cout << endl;
	}
	cout << "********************************" << endl;

	return result;
}

int longestCommonSubsequence(string s1, string s2) {

	int row = s1.length() + 1;
	int col = s2.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));
	return helper(0, s1, 0, s2, dp);
}

int longestCommonSubsequencePUREDP(string s1, string s2) {

	int row = s1.length() + 1;
	int col = s2.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col));

	// BASE CASE
	for (int i = 0; i < col; i++) {
		dp[s1.length()][i] = 0;
	}

	for (int i = 0; i < row; i++) {
		dp[i][s2.length()] = 0;
	}

	for (int i = s1.length() - 1; i >= 0; i--) {
		for (int j = s2.length() - 1; j >= 0; j--) {

			// when you're here you'll treat i,j as a dp state/subproblem
			// to solve this state you'll do the same thing as done in recursion

			int result;

			if (s1[i] == s2[j]) {
				result = 1 + dp[i + 1][j + 1];
			} else {
				int first = dp[i + 1][j];
				int second = dp[i][j + 1];

				result = max(first, second);
			}

			dp[i][j] = result;

		}
	}

	return dp[0][0];
}


int distinctSubseq(int si, string &s, int ti, string &t, vector<vector<int> > &dp) {
	// BASE CASE
	if (ti == t.length()) {
		dp[si][ti] = 1;
		return 1;
	}

	if (si == s.length()) {
		dp[si][ti] = 0;
		return 0;
	}

	if (dp[si][ti] != -1) {
		return dp[si][ti];
	}

	// REUCURSIVE CASE
	int count = 0;

	if (s[si] == t[ti]) {
		count += distinctSubseq(si + 1, s, ti + 1, t, dp);
	}

	count += distinctSubseq(si + 1, s, ti, t, dp);

	dp[si][ti] = count;

	for (int i = 0; i <= s.length(); i++) {
		for (int j = 0; j <= t.length(); j++) {
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "********************************" << endl;

	return count;
}

int numDistinct(string s, string t) {

	int row = s.length() + 1;
	int col = t.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));
	return distinctSubseq(0, s, 0, t, dp);
}

int numDistinctPUREDP(string s, string t) {

	int row = s.length() + 1;
	int col = t.length() + 1;

	vector<vector<long> > dp(row, vector<long> (col));

	// BASE CASE
	for (int i = 0; i < col; i++) {
		dp[s.length()][i] = 0;
	}

	for (int i = 0; i < row; i++) {
		dp[i][t.length()] = 1;
	}

	for (int si = s.length() - 1; si >= 0; si--) {
		for (int ti = t.length() - 1; ti >= 0; ti--) {

			// treat si and ti as a dp state
			// and do the same work as done in recursion

			long count = 0;

			if (s[si] == t[ti]) {
				count += dp[si + 1][ti + 1];
			}
			count += dp[si + 1][ti];


			// return count; instead we store the result in DP
			dp[si][ti] = count;
		}
	}

	return dp[0][0];
}

int main() {

	// cout << longestCommonSubsequence("abcde", "agdxe") << endl;

	cout << numDistinct("bbagg", "bag") << endl;

	return 0;
}