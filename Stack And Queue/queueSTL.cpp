#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {

	// queue<int> q;

	// q.push(2);
	// q.push(5);
	// q.push(16);
	// q.push(8);
	// q.push(45);

	// cout << "Size is " << q.size() << endl;

	// cout << "Front is having the value " << q.front() << endl;

	// q.pop();
	// q.pop();

	// cout << "Front is having the value " << q.front() << endl;

	// cout << "*****************LOOP*********" << endl;

	// while (!q.empty()) {
	// 	cout << q.front() << endl;
	// 	q.pop();
	// }

	// Deque

	deque<int> q;

	q.push_back(12);
	q.push_back(14);
	q.push_back(11);
	q.push_back(19);

	cout << "Size of deque is " << q.size() << endl;

	cout << "Front is " << q.front() << endl;

	cout << "Back is " << q.back() << endl;

	q.pop_front();

	cout << "Front is now after pop front " << q.front() << endl;

	return 0;
}