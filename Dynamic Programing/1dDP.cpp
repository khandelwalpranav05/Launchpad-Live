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

int perfectSquare(int n, vector<int> &dp) {
	//BASE CASE
	if (n == 0) {
		dp[0] = 0;
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	// RECURSIVE CASE
	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {
		int minPerfectSquareSubproblem = perfectSquare(n - i * i, dp);
		minValue = min(minValue, minPerfectSquareSubproblem);
	}

	minValue += 1;

	dp[n] = minValue;

	for (int i = 0; i <= 12; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "************************" << endl;

	return minValue;
}

int numSquaresMemo(int n) {
	vector<int> dp(n + 1, -1);

	return perfectSquare(n, dp);
}

int numSquaresPUREDP(int n) {

	vector<int> dp(n + 1);

	// BASE CASE
	dp[0] = 0;

	for (int problem = 1; problem <= n; problem++) {

		int minValue = INT_MAX;

		for (int i = 1; i * i <= problem; i++) {
			int minPerfectSquareSubproblem = dp[problem - i * i];
			minValue = min(minValue, minPerfectSquareSubproblem + 1);
		}

		dp[problem] = minValue;
	}

	return dp[n];
}

int robMemo(int si, vector<int> &nums, vector<int> &dp) {
	// BASE CASE
	if (si >= nums.size()) {
		return 0;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	// RECURSIVE CASE
	int include = robMemo(si + 2, nums, dp) + nums[si];
	int skip = robMemo(si + 1, nums, dp);

	int result = max(include, skip);

	dp[si] = result;

	for (int i = 0; i <= nums.size(); i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "************************" << endl;

	return result;
}

int rob(vector<int>& nums) {
	int n = nums.size();

	vector<int> dp(n + 2, -1);
	return robMemo(0, nums, dp);
}

int robPUREDP(vector<int>& nums) {
	int n = nums.size();

	vector<int> dp(n + 2);

	//BASE CASE
	dp[n + 1] = 0;
	dp[n] = 0;

	for (int si = n - 1; si >= 0; si--) {
		// RECURISVE CASE

		int include = nums[si] + dp[si + 2];
		int skip = dp[si + 1];

		int result = max(include, skip);

		dp[si] = result;
	}

	return dp[0];
}

int numTreesMemo(int n, vector<int> &dp) {
	if (n == 0 or n == 1) {
		dp[n] = 1;
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		int leftCount = numTreesMemo(i - 1, dp);
		int rightCount = numTreesMemo(n - i, dp);

		int myCountAsARootNode = leftCount * rightCount;
		ans += myCountAsARootNode;
	}

	dp[n] = ans;

	for (int i = 0; i <= 4; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "************************" << endl;

	return ans;
}


int numTrees(int n) {
	vector<int> dp(n + 1, -1);

	return numTreesMemo(n, dp);
}


int numTreesPUREDP(int n) {
	vector<int> dp(n + 1, -1);

	// BASE CASE
	dp[0] = 1;
	dp[1] = 1;

	for (int problem = 2; problem <= n; problem++) {

		// RECURSIVE CASE
		int ans = 0;

		for (int i = 1; i <= problem; i++) {
			int leftCount = dp[i - 1];
			int rightCount = dp[problem - i];

			int myCountAsARootNode = leftCount * rightCount;
			ans += myCountAsARootNode;
		}

		dp[problem] = ans;
	}

	return dp[n];
}

int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();

	if (n == 0) {
		return 0;
	}

	vector<int> dp(n, 1);


	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxLength = 1;

	for (int val : dp) {
		maxLength = max(maxLength, val);
	}

	return maxLength;
}

int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();

	if (n == 0) {
		return 0;
	}

	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		// harr baar maximum check karlo
	}

	int maxLength = 1;

	for (int val : dp) {
		maxLength = max(maxLength, val);
	}

	return maxLength;
}

int maxEnvelopes(vector<vector<int>>& envelopes) {

	int n = envelopes.size();
	if (n == 0) {
		return 0;
	}

	sort(envelopes.begin(), envelopes.end());

	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {

			if (envelopes[j][0] < envelopes[i][0] and envelopes[j][1] < envelopes[i][1]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
	}

	int maxValue = 1;

	for (int val : dp) {
		maxValue = max(val, maxValue);
	}

	return maxValue;
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

	// int start = 0;
	// int end = 10;

	// cout << countBoardPath(start, end);

	// int dp[end + 1];
	// memset(dp, -1, sizeof(dp));
	// cout << countBoardPathMemo(start, end, dp) << endl;

	// cout << "Number of function call for countBoardPath " << check1 << endl;
	// cout << "Number of function call for countBoardPathMemo " << check2 << endl;


	// cout << countBoardPathPUREDP(start, end) << endl;
	// int n = 12;
	// cout << numSquaresMemo(n) << endl;

	// vector<int> v({2, 7, 9, 3, 1});
	// cout << rob(v) << endl;

	cout << numTrees(4) << endl;

	return 0;
}