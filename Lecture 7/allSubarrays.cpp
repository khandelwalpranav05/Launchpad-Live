#include <iostream>

using namespace std;

int main() {

	int arr[]  = {1, 2, 3, 4};
	int n = 4;

	for (int start = 0; start < n; start++) {

		for (int end = start; end < n; end++) {

			// cout << "start with " << start << " , end with " << end << endl;

			for (int k = start; k <= end; k++) {

				cout << arr[k] << " ";

			}
			cout << endl;
		}
	}

	return 0;
}