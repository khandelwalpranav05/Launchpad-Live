#include <iostream>
#include <list>

using namespace std;

// generic ?
class Queue {
	list<int> storage;

public: // B
	void push(int data) {
		this->storage.push_back(data);
	}

	void pop() {
		this->storage.pop_front();
	}

	int getFront() {
		return this->storage.front();
	}

	int size() {
		return this->storage.size();
	}

	bool empty() {
		return this->storage.empty();
	}
};

int main() {

	Queue q;

	q.push(2);
	q.push(5);
	q.push(16);
	q.push(8);
	q.push(45);

	cout << "Front is having the value " << q.getFront() << endl;

	q.pop();
	q.pop();

	cout << "Front is having the value " << q.getFront() << endl;

	cout << "*****************LOOP*********" << endl;

	while (!q.empty()) {
		cout << q.getFront() << endl;
		q.pop();
	}


	return 0;
}