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

bool isValid(int arr[], int n, int cows, int distanceLimit) {

	int previousCowPosition = arr[0];
	int cowsPlacedUptilThisPoint = 1;

	for (int i = 1; i < n; i++) {

		int currentCowPosition = arr[i];

		int gapBetweenCows = currentCowPosition - previousCowPosition;
		if (gapBetweenCows >= distanceLimit) {
			cowsPlacedUptilThisPoint++;
			previousCowPosition = arr[i];

			if (cowsPlacedUptilThisPoint == cows) {
				return true;
			}
		}
	}

	return false;
}

int aggressiveCows(int arr[], int n, int cows) {

	sort(arr, arr + n);

	int minDist = 1;
	int maxDist = arr[n - 1] - arr[0];

	int start = minDist;
	int end = maxDist;

	int ans = 1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (isValid(arr, n, cows, mid)) {
			ans = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}

	}

	return ans;
}

bool canGive(long n, long m, long x, long y, long a) {
	return (x * a <= m + y * (n - a));
}

long winningCBSchorlarship(long n, long m, long x, long y) {

	long start = 0;
	long end = n;

	long ans = 0;

	while (start <= end) {

		long mid = (start + end) / 2;

		if (canGive(n, m, x, y, mid)) {
			ans = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}

	}

	return ans;
}

void merge(int arr[], int start, int end) {

	int mid = (start + end) / 2;

	int i = start; // iterate left Hfl
	int j = mid + 1; // iterate right Half


	int temp[end - start + 1];
	int k = 0; // iterate temp array

	while (i <= mid and j <= end) {

		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;

		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (j <= end) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	while (i <= mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	// temp is sorted but arr is not sorted

	int pos = 0;
	for (int x = start; x <= end; x++) {
		arr[x] = temp[pos];
		pos++;
	}

	//DONE
}

void mergeSort(int arr[], int start, int end) {
	// BASE CASE
	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;

	mergeSort(arr, start, mid); // left Half
	mergeSort(arr, mid + 1, end); // right Half

	merge(arr, start, end);
}

int main() {

	// int arr[] = {12, 23, 31, 45, 57, 69, 73, 82};
	// int n = 8;
	// int key = 731;

	// cout << binarySearch(arr, n, key) << endl;

	// int board[] = {10, 20, 30, 40};
	// int n = 4;
	// int painters = 2;

	// cout << painterProblem(board, n, painters, 1) << endl;

	// int barns[] = {2, 1, 4, 9, 8};
	// int n = 5;
	// int cows = 3;

	// cout << aggressiveCows(barns, n, cows) << endl;

	// long n = 5;
	// long m = 10;
	// long x = 2;
	// long y = 1;

	// cout << winningCBSchorlarship(n, m, x, y) << endl;

	// int arr[] = {3, 5, 8, 12, 2, 4, 16, 19};
	// int n = 8;

	// merge(arr, 0, n - 1);

	int arr[] = {5, 3, 12, 8, 19, 16, 2, 4};
	int n = 8;
	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}