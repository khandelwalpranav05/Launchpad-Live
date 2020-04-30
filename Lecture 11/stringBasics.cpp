#include <iostream>

using namespace std;

int main() {

	// string str = "Pranav";
	// string str;
	// cin >> str;

	// string str = "Pranav";

	// cout << str << endl;
	// cout << str.length() << endl;

	// cout << str[1] << endl;
	// str[1] = 'O';

	// cout << str << endl;

	// string s1 = "Coding ";
	// string s2 = "Blocks";

	// string c = s1 + s2;
	// cout << c << endl;

	// string a = s1 + "in c++"; //  string + char array ->typecasting-> string + string
	// cout << a << endl;

	// string b = "Pranav " + (string)"khandelwal";
	// cout << b << endl;

	// string str = "test";

	// string a = "code" + str;
	// cout << a << endl;

	// char a = 'A' + 2; //implicit typecasting
	// cout << a << endl;

	// bool b = 567;
	// int a = b + 45;
	// cout << a << endl;

	// char ch  = 'B';
	// cout << (int)ch << endl; // explicit typecasting

	// string str = "test";

	// string x = "code " + str + "check" ;
	// cout << x << endl;

	// string xyz = "abcdefhg";

	// cout << xyz.substr(2, 4) << endl;
	// cout << xyz.substr(3) << endl;

	// string arr[] = {"coding", "blocks", "C++", "launchpad"};
	// for (int i = 0; i < 4; i++) {
	// 	cout << arr[i] << endl;
	// }
	// cout << endl;

	string str = "Pranav";

	int arr[200] = {0};

	char ch = str[2];
	arr[ch] = 45;

	cout << arr[97] << endl;

	return 0;
}