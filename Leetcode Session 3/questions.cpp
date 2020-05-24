#include <iostream>
#include <vector>

using namespace std;

bool isPerfectSquare(int num) {

	int start = 1;
	int end = num;

	while (start <= end) {

		long mid = start + (end - start) / 2;

		if (mid * mid == num) {
			return true;
		} else if (mid * mid < num) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return false;
}


int MountainPeak(vector<int> &arr, int start, int end) {
	// BASE CASE
	if (start == end) {
		return start;
	}

	int mid = (start + end) / 2;

	if (arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1]) {
		return mid;
	}

	if (arr[mid] < arr[mid + 1]) {
		return MountainPeak(arr, mid + 1, end);
	} else {
		return MountainPeak(arr, start, mid - 1);
	}
}

int peakIndexInMountainArray(vector<int>& A) {

	int n = A.size();

	return helper(A, 0, n - 1);
}

int firstBadVersion(int n) {

	int start = 1;
	int end = n;

	int ans;

	while (start <= end) {

		int midVersion = start + (end - start) / 2;

		if (isBadVersion(midVersion)) { // if the mid Version is true
			ans = midVersion;
			end = midVersion - 1;
		} else { // if the mid version is false
			start = midVersion + 1;
		}
	}

	return ans;
}

int isPossible(vector<int> &nums, int m, int midSubarraySumLimit) {
	int n = nums.size();

	int splits = 1;
	long splitSum = 0;

	for (int i = 0; i < n; i++) {

		splitSum += nums[i];

		if (splitSum > midSubarraySumLimit) {

			splits++;
			splitSum = nums[i];

			if (splits > m) {
				return false;
			}
		}

	}

	return true;
}

int numSquares(int n) {
	// BASE CASE
	if (n == 0) {
		return 0;
	}

	// RECURIVE CASE
	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {
		int minPerfectSquareRequiredBySubproblem = numSquares(n - i * i);
		minValue = min(minPerfectSquareRequiredBySubproblem, minValue);
	}

	return minValue + 1;
}

int splitArray(vector<int>& nums, int m) {
	int n = nums.size();

	int maxValue = nums[0];
	long total = nums[0];

	for (int i = 1; i < n; i++) {
		maxValue = max(maxValue, nums[i]);
		total += nums[i];
	}

	int start = maxValue;
	long end = total;

	int ans;

	while (start <= end) {
		int midSubarraySumLimit = start + (end - start) / 2;

		if (isPossible(nums, m, midSubarraySumLimit)) {
			ans = midSubarraySumLimit;
			end = midSubarraySumLimit - 1;
		} else {
			start = midSubarraySumLimit + 1;
		}
	}

	return ans;
}

int houseRobber(int si, vector<int> &nums) {
	// BASE CASE
	if (si >= nums.size()) {
		return 0;
	}

	// RECURSIVE CASE
	int robThisHouse = nums[si] + houseRobber(si + 2, nums);
	int dontRobThisHouse = houseRobber(si + 1, nums);

	int result = max(robThisHouse, dontRobThisHouse);

	return result;
}

int rob(vector<int>& nums) {

	return houseRobber(0, nums);
}

bool partitionPossible(int si, vector<int> &nums, int sum, int total) {
	// BASE CASE
	if (sum == total / 2) {
		return true;
	}

	if (sum > total / 2 or si == nums.size()) {
		return false;
	}

	// RECURSIVE CASE
	bool include = partitionPossible(si + 1, nums, sum + nums[si], total);
	bool exclude = partitionPossible(si + 1, nums, sum, total);

	if (include or exclude) {
		return true;
	}

	return false;
}

bool canPartition(vector<int>& nums) {
	int n = nums.size();

	int total = 0;

	for (int i = 0; i < n; i++) {
		total += nums[i];
	}

	if (total & 1) {
		return false;
	}

	// If the total is an even value
	return partitionPossible(0, nums, 0, total);
}


int helper(int si, vector<int> &nums, int sum, int target) {
	// BASE CASE
	if (si == nums.size()) {
		if (sum == target) {
			return 1;
		}
		return 0;
	}


	// RECURSIVE CASE
	int positive = helper(si + 1, nums, sum + nums[si], target);
	int negative = helper(si + 1, nums, sum - nums[si], target);

	// my work done
	int count = positive + negative;
	return count;
}

int findTargetSumWays(vector<int>& nums, int S) {

	return helper(0, nums, 0, S);
}

int main() {


	return 0;
}