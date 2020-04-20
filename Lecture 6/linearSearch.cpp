#include <iostream>

using namespace std;

int main() {

	int arr[6] = {4, 7, 1, 8, 2, 0};
	int key = 14;

	int idx = -1;

	for (int i = 0; i < 6; i++) {
		if (arr[i] == key) {
			idx = i;
			break;
		}
	}

	cout << key << " was found at " << idx << " index" << endl;

	return 0;
}