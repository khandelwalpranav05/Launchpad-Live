#include <iostream>
#include <queue>

using namespace std;

int main() {

	queue<int> q;

	q.push(2);
	q.push(5);
	q.push(16);
	q.push(8);
	q.push(45);

	cout << "Size is " << q.size() << endl;

	cout << "Front is having the value " << q.front() << endl;

	q.pop();
	q.pop();

	cout << "Front is having the value " << q.front() << endl;

	cout << "*****************LOOP*********" << endl;

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	return 0;
}