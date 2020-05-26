#include <iostream>

using namespace std;

template <typename T>
class Stack {
	int top;
	int maxSize;
	T* arr; // if this array would have been static

public:
	Stack(int maxSize) {
		// initialize our array in constructor when new obj is created
		this->maxSize = maxSize;
		this->arr = new T[this->maxSize];
		this->top = -1;
	}

	void push(T data) {
		if (this->top == this->maxSize - 1) {
			cout << "Stack Overflow!" << endl;
			return;
		}

		this->top++;
		this->arr[this->top] = data;
	}

	void pop() {
		if (this->empty()) {
			cout << "Stack Underflow" << endl;
			return;
		}

		this->top--;
	}

	T getTop() {
		return this->arr[this->top];
	}

	int size() {
		return this->top + 1;
	}

	bool empty() {
		// if (this->top == -1) {
		// 	return true;
		// }
		// return false;
		return this->top == -1;
	}
};

class Car {
	int price;
	int speed;
	string name;
};

int main() {

	Stack<Car> s;

	// Stack<int> s(5);

	// s.push(5);
	// s.push(2);
	// s.push(4);
	// s.push(6);
	// s.push(8);

	// s.push(78); // overflow

	// cout << s.getTop() << endl; // 8

	// while (!s.empty()) {
	// 	cout << "Current Top is " << s.getTop() << endl;
	// 	s.pop();
	// 	cout << "Popped" << endl;
	// }

	// if (s.empty()) { // true
	// 	cout << "Stack is empty!" << endl;
	// }

	Stack<char> s(5);

	s.push('A');
	s.push('t');
	s.push('c');
	s.push('u');
	s.push('a');
	s.push('p');

	while (!s.empty()) {
		cout << "Current Top is " << s.getTop() << endl;
		s.pop();
		cout << "Popped" << endl;
	}

	return 0;
}