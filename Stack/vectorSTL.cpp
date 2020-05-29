#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v;

	v.push_back(2);
	v.push_back(12);
	v.push_back(6);
	v.push_back(58);
	v.push_back(32);
	v.push_back(24);

	for (int val : v) { // for each loop
		cout << val << " ";
	}
	cout << endl;

	v[0] = 543;

	cout << "Value on front " << v.front() << endl;
	cout << "Value on back " << v.back() << endl;

	v.pop_back();
	cout << "Value on back after pop back " << v.back() << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	sort(v.begin(), v.end());

	for (int val : v) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
