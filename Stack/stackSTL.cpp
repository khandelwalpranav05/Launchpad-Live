#include <iostream>
#include <stack>

using namespace std;

int main() {

	stack<int> s;

	s.push(5);
	s.push(2);
	s.push(4);
	s.push(6);
	s.push(8);

	s.push(78);

	cout << s.top() << endl; // 78

	cout << "Size of the stack is " << s.size() << endl; // 6

	while (!s.empty()) {
		cout << "Current Top is " << s.top() << endl;
		s.pop();
		cout << "Popped" << endl;
	}

	if (s.empty()) { // true
		cout << "Stack is empty!" << endl;
	}

	return 0;
}