#include <iostream>

using namespace std;

int main() {

	int arr[] = {1, 2, 3, 3, 2, 12};
	int n = 6;

	int left = 0;
	int right = n - 1;

	bool flag = false;

	while (left <= right) {
		if (arr[left] != arr[right]) {
			cout << "Not a Palindrome" << endl;
			flag = true;
			break;
		} else {
			left++;
			right--;
		}
	}

	if (flag == false) {
		cout << "Palindrome" << endl;
	}

	return 0;
}