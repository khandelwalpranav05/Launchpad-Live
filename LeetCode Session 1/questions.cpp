#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

void sortColors(int nums[], int n) {
	int count[3] = {0};

	for (int i = 0; i < n; i++) {
		int val = nums[i];
		count[val]++;
	}

	int idx = 0;

	for (int i = 0; i < n; i++) {
		while (count[idx] == 0) {
			idx++;
		}

		nums[i] = idx;
		count[idx]--;
	}
}

int containerMostWater(int height[], int n) {
	int left = 0;
	int right = n - 1;

	int maxArea = 0;

	while (left < right) {
		int minHeight = min(height[left], height[right]);

		int gap = right - left;

		int currArea = minHeight * gap;

		if (currArea > maxArea) {
			maxArea = currArea;
		}

		if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}
	}

	return maxArea;
}

int minSubArrayLen(int s, int nums[], int n) {
	int left = 0;
	int right = 0;

	int sum = 0;

	int minLen = INT_MAX;

	while (right < n) {
		sum += nums[right];

		while (sum >= s) {
			int len = right - left + 1;
			if (len < minLen) {
				minLen = len;
			}

			sum = sum - nums[left];
			left++;
		}

		right++;
	}

	if (minLen == INT_MAX) {
		return 0;
	}

	return minLen;
}

int longestOnes(int A[], int n, int K) {
	int left = 0;
	int right = 0;

	int maxLen = 0;

	int utilize = 0;

	while (right < n) {
		if (A[right] == 0) {
			utilize++;
		}

		while (utilize > K) {
			if (A[left] == 0) {
				utilize--;
			}

			left++;
		}

		int len = right - left + 1;
		if (len > maxLen) {
			maxLen = len;
		}

		right++;
	}

	return maxLen;
}

int trappingRainWater(int height[], int n) {
	if (n == 0) {
		return 0;
	}

	int left[n];
	int right[n];

	left[0] = height[0];

	for (int i = 1; i < n; i++) {
		if (height[i] > left[i - 1]) {
			left[i] = height[i];
		} else {
			left[i] = left[i - 1];
		}
	}

	right[n - 1] = height[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		if (height[i] > right[i + 1]) {
			right[i] = height[i];
		} else {
			right[i] = right[i + 1];
		}
	}

	int totalWater = 0;

	for (int i = 0; i < n; i++) {
		int val = min(left[i], right[i]) - height[i];
		totalWater += val;
	}

	return totalWater;
}

int main() {


	return 0;
}