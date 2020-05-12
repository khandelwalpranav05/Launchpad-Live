#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (arr[mid] == key) {
			return mid;
		} else if (arr[mid] > key) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return -1;
}

int lowerBound(int arr[], int n, int key) {
	int start = 0;
	int end = n - 1;

	int ans = -1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (arr[mid] == key) {
			ans = mid;
			end = mid - 1;
		} else if (arr[mid] > key) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

int upperBound(int arr[], int n, int key) {

	//HOMEWORK

	return 0;
}

int find(vector<int> &nums, int start, int end, int n) {
	// MY WORK
	int mid = (start + end) / 2;
	// 1st               // 2nd
	if ((mid == 0 or nums[mid - 1] < nums[mid]) and ( mid == n - 1 or nums[mid] > nums[mid + 1])) {
		return mid;
	}

	// RECURSION
	if (nums[mid] < nums[mid + 1]) {
		return find(nums, mid + 1, end, n); // subproblem
	} else {
		return find(nums, start, mid - 1, n); // subproblem
	}
}

int findPeakElement(vector<int>& nums) {
	int n = nums.size();

	int start = 0;
	int end = n - 1;


	return find(nums, start, end, n);
}

bool isPossible(int board[], int n, int painters, int deadline) {

	int countPainters = 1;
	int painterTime = 0;

	for (int i = 0; i < n; i++) {

		painterTime += board[i];

		if (painterTime > deadline) {
			countPainters++;
			painterTime = board[i];

			if (countPainters > painters) {
				return false;
			}
		}
	}

	return true;
}

int painterProblem(int board[], int n, int painters, int perUnitTime) {

	int minTime = INT_MIN;
	int maxTime = 0;

	for (int i = 0; i < n; i++) {
		maxTime += board[i];
		minTime = max(board[i], minTime);
	}

	int start = minTime;
	int end = maxTime;

	int ans = maxTime;

	while (start <= end) {

		int mid = (start + end) / 2;
		int deadline = mid;

		if (isPossible(board, n, painters, deadline)) {
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}

	}

	return ans;
}

int main() {

	// int arr[] = {12, 23, 31, 45, 57, 69, 73, 82};
	// int n = 8;
	// int key = 731;

	// cout << binarySearch(arr, n, key) << endl;

	int board[] = {10, 20, 30, 40};
	int n = 4;
	int painters = 2;

	cout << painterProblem(board, n, painters, 1) << endl;

	return 0;
}