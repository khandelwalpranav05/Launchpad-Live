#include <iostream>
#include <list>


using namespace std;

int main() {

	list<int> pranav;

	pranav.push_back(3); // insert at tail
	pranav.push_front(67); // insert at head

	pranav.push_back(89);
	pranav.push_back(12);
	pranav.push_back(45);

	cout << pranav.front() << endl; // get value at head

	cout << pranav.back() << endl; // get value at tail

	// iterate over our linked list
	// for each loop

	for (int val : pranav) {
		cout << val << " -> ";
	}
	cout << endl;

	// pranav.pop_front(); // delete at head

	// pranav.pop_back(); // delete at tail

	// cout << "After Deletion" << endl;

	// for (int val : pranav) {
	// 	cout << val << " -> ";
	// }
	// cout << endl;

	pranav.sort(); // O(nlogn)

	cout << "After Sorting" << endl;

	for (int val : pranav) {
		cout << val << " -> ";
	}
	cout << endl;

	return 0;
}