#include <iostream>

using namespace std;

string toggle(string str) {

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			//SMALL
			str[i] = str[i] + 32;
		} else if (str[i] >= 'a' && str[i] <= 'z') {
			//CAPITAL
			str[i] = str[i] - 32;
		}
	}

	return str;
}

int maxFreq(string str) { // n
	int freq[123] = {0};

	// "codicng"
	//  012345

	for (int i = 0; i < str.length(); i++) {
		int val = str[i]; // 97<-'a'

		freq[val]++;

		// freq[str[i]]++;
	}

	int maxValue = INT_MIN;

	for (int i = 97; i < 123; i++) {
		if (maxValue < freq[i]) {
			maxValue = freq[i];
		}
	}

	return maxValue;
}

void printAllSubstrings(string str) {
	int n = str.length();

	for (int i = 0; i < n; i++) {

		int startIndex = i;

		for (int len = 1; len <= (n - i) ; len++) {
			cout << str.substr(startIndex, len) << endl;
		}
	}
}

int main() {

	// string str = "NamaN";
	// cout << toggle(str) << endl;

	// string str = "ababcbcddbbaabzzvmmn";
	// cout << maxFreq(str) << endl;

	printAllSubstrings("abcd");

	return 0;
}