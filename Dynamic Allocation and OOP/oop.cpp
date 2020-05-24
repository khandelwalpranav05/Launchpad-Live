#include <iostream>

using namespace std;

class Car {
private:
	int speed;
	string name;

public:
	// data members/attributes/properties
	int price;

	void ignition() {
		cout << "Starting my car with the speed of " << speed << endl;
	}

	void display() {
		cout << "Speed -> " << this->speed << endl;
		cout << "Name -> " << this->name << endl;
		cout << "Price -> " << this->price << endl;
		cout << "******************************" << endl;
	}

	// By Default Constructor

	// When I write my own constructor the bydefault constructor is overridden
	Car() {
		cout << "This is my new Constructor" << endl;
	}

	// Parametrised Constructor
	Car(string name, int speed, int price) {

		// At this Point name is a property and name is a temp variable
		cout << "Parametrised Constructor is called" << endl;
		this->name = name;
		this->speed = speed;
		this->price = price;
	}

	Car(string name) {
		cout << "Parametrised Constructor but only String name is required" << endl;
		this->name = name;
	}

	Car(string name, int speed) {
		cout << "Parametrised Constructor With name and speed" << endl;
		this->name = name;
		this->speed = speed;
	}

	// setter
	void setSpeed(int speed) {
		// cout << "Setting the speed value!" << endl;
		if (speed < 0) {
			cout << "Invalid Input for speed!" << endl;
			return;
		}
		this->speed = speed;
	}

	void setName(string name) {
		if (name.length() < 3) {
			cout << "Please enter a name greater than 3 characters" << endl;
			return;
		}

		this->name = name;
	}

	// getters
	int getSpeed() {
		return this->speed;
	}

	string getName() {
		return this->name;
	}

	~Car() { // override the by default destructor
		cout << "Car which has the name as " << this->name << " and speed as " << this->speed << " is being destroyed" << endl;
		// cout << "Object is being destroyed!" << endl;
	}
};

int main() {

	// Car c;
	// // c.speed = -100;
	// c.setSpeed(57);
	// // c.name = "Creta";
	// c.setName("Polo");
	// c.price = 1000;

	// cout << "Speed of the car is " << c.getSpeed() << endl;
	// cout << "Name of the Car is " << c.getName() << endl;

	// Car t("Honda", 120, 7000);
	Car *p = new Car("Volkswagon", 450, 90000);

	cout << (*p).price << endl;
	cout << p->price << endl;

	(*p).display();
	p->display();

	// c.display();

	// Car a("Honda City", 200, 10000);
	// a.display();

	// // Car x("Pranav");

	// Car b("Jazz", 190);
	// b.display();

	// c.ignition();

	// c.display();

	// Car d; // different object/instance of a concept/class named car
	// d.name = "Merc";
	// d.speed = 150;
	// d.price = 20000;

	// d.ignition();

	// d.display();

	// cout << sizeof(c) << endl;

	// int
	// float
	// char
	// long


	// string

	delete p;

	return 0;
}