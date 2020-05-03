#include <iostream>

using namespace std;

int balancedStringSplit(string s) {

	int leftCount = 0;
	int rightCount = 0;

	int totalCount = 0;

	for (int i = 0; i < s.length(); i++) {

		char ch = s[i];

		if (ch == 'L') {
			leftCount++;
		} else {
			rightCount++;
		}

		if (leftCount == rightCount) {
			totalCount += 1;
			leftCount = 0;
			rightCount = 0;
		}
	}

	return totalCount;
}

bool isPowerOfTwo(int n) {
	if (n <= 0) {
		return false;
	}

	int count = __builtin_popcount(n);
	return count == 1;
}

bool isPowerOfTwoSecond(int n) {
	if (n <= 0) {
		return false;
	}

	int val = n & (n - 1);

	return val == 0;
}

int rangeBitwiseAnd(int m, int n) {
	int steps = 0;

	while (m != n) {
		m = m >> 1;
		n = n >> 1;

		steps++;
	}

	m = m << steps;
	return m;
}

int maxSubarraySumCircular(vector<int>& arr) {
	int n = arr.size();

	int currMaxSum = arr[0];
	int maxSum = arr[0];

	int currMinSum = arr[0];
	int minSum = arr[0];

	int total = arr[0];

	for (int i = 1; i < n; i++) {
		//KADANE'S ALGO FOR MAX SUM
		currMaxSum = max(currMaxSum + arr[i], arr[i]);
		maxSum = max(maxSum, currMaxSum);

		//KADANE'S ALGO FOR MIN SUM
		currMinSum = min(currMinSum + arr[i], arr[i]);
		minSum = min(minSum, currMinSum);

		//TOTAL SUM
		total += arr[i];
	}

	if (maxSum < 0) {
		return maxSum;
	}

	if (maxSum > (total - minSum)) {
		return maxSum;
	} else {
		return total - minSum;
	}
}

int countSubstrings(string s) {
	int count = 0;

	for (int i = 0; i < s.length(); i++) {

		// ODD LENGTH
		int left = i;
		int right = i;

		while (left >= 0 and right < s.length()) {
			if (s[left] == s[right]) {
				count++;
				left--;
				right++;
			} else {
				break;
			}
		}

		//EVEN LENGTH
		left = i;
		right = i + 1;

		while (left >= 0 and right < s.length()) {
			if (s[left] == s[right]) {
				count++;
				left--;
				right++;
			} else {
				break;
			}
		}
	}

	return count;
}

int main() {



	return 0;
}