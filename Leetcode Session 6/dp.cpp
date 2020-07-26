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

int helper(int si, vector<int> &coins, int amount, vector<vector<int>> &dp) {
	if (amount == 0) {
		return 1;
	}

	if (si == coins.size()) {
		return 0;
	}

	if (dp[si][amount] != -1) {
		return dp[si][amount];
	}

	int count = 0;

	// include

	if (coins[si] <= amount) {
		count += helper(si, coins, amount - coins[si], dp);
	}

	// skip
	count += helper(si + 1, coins, amount, dp);

	dp[si][amount] = count;

	return count;
}

int changeMemo(int amount, vector<int>& coins) {

	int row = coins.size() + 1;
	int col = amount + 1;

	vector<vector<int>> dp(row, vector<int> (col, -1));

	return helper(0, coins, amount, dp);
}

int changePUREDP(int amount, vector<int>& coins) {

	int n = coins.size();

	int row = n + 1;
	int col = amount + 1;

	vector<vector<int>> dp(row, vector<int> (col, -1));

	// BASE CASE

	for (int amt = 0; amt <= amount; amt++) {
		dp[n][amt] = 0;
	}

	for (int si = 0; si <= n; si++) {
		dp[si][0] = 1;
	}


	for (int si = n - 1; si >= 0; si--) {
		for (int amt = 1; amt <= amount; amt++) {

			// RECURSIVE

			int count = 0;

			// Include
			if (coins[si] <= amt) {
				count += dp[si][amt - coins[si]];
			}

			// skip
			count += dp[si + 1][amt];

			dp[si][amt] = count;
		}
	}

	return dp[0][amount];
}

int minInsertions(string s) {
	int n = s.length();

	int row = n;  // left range 0->n-1
	int col = n; // right range 0->n-1

	vector<vector<int>> dp(row, vector<int> (col, -1));

	return helper(s, 0, n - 1, dp);
}

int helper(string &str, int left, int right, vector<vector<int>> &dp) {
	if (left >= right) {
		return 0;
	}

	if (dp[left][right] != -1) {
		return dp[left][right];
	}

	int result;

	if (str[left] == str[right]) {
		result = helper(str, left + 1, right - 1, dp);
	} else {
		int first = helper(str, left, right - 1, dp) + 1;
		int last = helper(str, left + 1, right, dp) + 1;

		result = min(first, last);
	}

	dp[left][right] = result;

	return result;
}


bool canPartition(vector<int>& nums) {

	int total = 0;

	for (int num : nums) {
		total += num;
	}

	if (total & 1) {
		return false;
	}

	int half = total / 2;

	int row = nums.size() + 1;
	int col = half + 1;

	vector<vector<int>> dp(row, vector<int> (col, -1));

	return helper(0, nums, 0, half, dp);
}

bool helper(int si, vector<int> &nums, int sum, int half, vector<vector<int>> &dp) {
	if (sum == half) {
		return true;
	}

	if (sum > half or si == nums.size()) {
		return false;
	}

	if (dp[si][sum] != -1) {
		return dp[si][sum];
	}

	bool include = helper(si + 1, nums, sum + nums[si], half, dp);
	bool exclude = helper(si + 1, nums, sum, half, dp);

	dp[si][sum] = include or exclude;

	return dp[si][sum];
}

bool wordBreak(string s, vector<string>& wordDict) {

	unordered_map<string, bool> dp;
	return helper(s, wordDict, dp);
}

bool helper(string str, vector<string> &wordDict, unordered_map<string, bool> &dp) {
	// BASE CASE
	if (str.length() == 0) {
		return true;
	}

	if (dp.count(str)) {
		return dp[str];
	}

	for (string word : wordDict) {
		// word-> cats
		// str -> catsanddog

		int len = word.length();

		if (len <= str.length()) {

			// str -> catsanddog
			string extractWord = str.substr(0, len);
			// extractedWord -> cats

			if (extractWord == word) {
				string ros = str.substr(len);

				bool recursionResult = helper(ros, wordDict, dp);

				if (recursionResult) {
					dp[str] = true;
					return true;
				}
			}
		}
	}

	dp[str] = false;
	return false;
}

int findMaxForm(vector<string>& strs, int m, int n) {
	int size = strs.size();

	int row =  size + 1; // si 0->size
	int col = m + 1; // m  prob(m) -> base(0)
	int zaxis = n + 1; // n

	vector<vector<vector<int>>> dp(row, vector<vector<int>> (col, vector<int> (zaxis, -1)));

	return helper(0, strs, m, n, dp);
}

int helper(int si, vector<string> &strs, int m, int n, vector<vector<vector<int>>> &dp) {
	// BASE CASE
	if (si == strs.size()) {
		return 0;
	}

	if (n == 0 and m == 0) {
		return 0;
	}

	if (dp[si][m][n] != -1) {
		return dp[si][m][n];
	}

	string key = strs[si];

	int ones = 0;
	int zeros = 0;

	for (char ch : key) {
		if (ch == '1') {
			ones++;
		} else {
			zeros++;
		}
	}

	int include = 0;
	if (zeros <= m and ones <= n) {
		include = helper(si + 1, strs, m - zeros, n - ones, dp) + 1;
	}

	int exclude = helper(si + 1, strs, m, n, dp);

	int result = max(include, exclude);

	dp[si][m][n] = result;

	return result;
}

int minFallingPathSum(vector<vector<int>>& arr) {

	int row = arr.size();
	int col = arr.size();

	vector<vector<int>> dp(row, vector<int> (col, -1));

	int minValue = INT_MAX;
	for (int start = 0; start < arr.size(); start++) {
		int ans = helper(arr, 0, start, dp);
		minValue = min(minValue, ans);
	}

	return minValue;
}

int helper(vector<vector<int>>& arr, int row, int col, vector<vector<int>> &dp) {
	// BASE CASE
	if (row == arr.size() - 1) {
		return arr[row][col];
	}

	if (dp[row][col] != -1) {
		return dp[row][col];
	}

	int minValue = INT_MAX;

	int myValue = arr[row][col];

	for (int i = 0; i < arr.size(); i++) {
		if (i == col) {
			continue;
		}

		int subProblemPathSum = helper(arr, row + 1, i, dp);
		int myAnswer = subProblemPathSum + myValue;

		minValue = min(minValue, myAnswer);
	}

	dp[row][col] = minValue;

	return minValue;
}

int numRollsToTarget(int d, int f, int target) {

	// target-> 0 - target
	// dice -> 0 - d

	return helper(d, target, f);
}

int helper(int d, int target, int f) {
	// BASE CASE
	if (d == 0 and target == 0) {
		return 1;
	}

	if (d == 0 or target == 0) {
		return 0;
	}

	int count = 0;

	for (int i = 1; i <= f; i++) {
		if (i > target) {
			break;
		}

		int recursionResult = helper(d - 1, target - i, f); // subproblem
		count = count + recursionResult;
	}

	return count;
}

int numRollsToTarget(int d, int f, int target) {

	// target-> 0 - target
	// dice -> 0 - d

	return helper(d, target, f);
}

int helper(int d, int target, int f) {
	// BASE CASE
	if (d == 0 and target == 0) {
		return 1;
	}

	if (d == 0 or target == 0) {
		return 0;
	}

	int count = 0;

	for (int i = 1; i <= f; i++) {
		if (i > target) {
			break;
		}

		int recursionResult = helper(d - 1, target - i, f); // subproblem
		count = count + recursionResult;
	}

	return count;
}

int numberOfArrays(string s, int k) {

	return helper(0, s, k);
}

int helper(int si, string s, int k) {
	// BASE CASE
	if (si == s.length()) {
		return 1;
	}

	if (s[si] == '0') {
		return 0;
	}

	int count = 0;

	int val = 0;

	for (int i = si; i < s.length(); i++) {

		char ch = s[i]; // 3
		int num = ch - '0';  // int 3

		val = val * 10 + num; // 2*10 + 3 -> 23

		if (val > k) {
			break;
		}

		int recursionResult = helper(i + 1, s, k);
		count = count + recursionResult;
	}

	return count;
}

int maxScore(vector<int>& cardPoints, int k) {
	int n = cardPoints.size();

	int row = n + 1;
	int col = n + 1;
	int zaxis = k + 1;

	vector<vector<vector<int>>> dp(row, vector<vector<int>> (col, vector<int> (zaxis, -1)));

	return helper(cardPoints, k, 0, n - 1, dp);
}

int helper(vector<int>& cardPoints, int k, int start, int end, vector<vector<vector<int>>> &dp) {
	// BASE CASE
	if (k == 0 or start > end) {
		return 0;
	}

	if (dp[start][end][k] != -1) {
		return dp[start][end][k];
	}

	int aage  = cardPoints[start] + helper(cardPoints, k - 1, start + 1, end, dp);
	int pichhe = cardPoints[end] + helper(cardPoints, k - 1, start, end - 1, dp);

	int result = max(aage, pichhe);

	dp[start][end][k] = result;

	return result;
}

int maxScore(vector<int>& cardPoints, int k) {
	int n = cardPoints.size();

	int sum = 0;
	for (int card : cardPoints) {
		sum += card;
	}

	int windowSum = 0;
	for (int i = 0; i < n - k; i++) {
		windowSum += cardPoints[i];
	}

	int left = 0;
	int right = n - k;

	int maxValue = 0;

	while (right < n) {

		int currSum = sum - windowSum;
		maxValue = max(maxValue, currSum);

		windowSum += cardPoints[right];
		windowSum -= cardPoints[left];

		left++;
		right++;
	}

	int currSum = sum - windowSum;
	maxValue = max(maxValue, currSum);

	return maxValue;
}

int main() {


	return 0;
}