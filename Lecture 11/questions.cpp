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

int maxFreq(string str) {
	int freq[123] = {0};

	for (int i = 0; i < str.length(); i++) {
		int val = str[i]; // 97<-'a'

		freq[val]++;

		// freq[str[i]]++;
	}

	int maxValue = INT_MIN;

	for (int i = 0; i < 123; i++) {
		if (maxValue < freq[i]) {
			maxValue = freq[i];
		}
	}

	return maxValue;
}

int main() {

	// string str = "NamaN";
	// cout << toggle(str) << endl;

	string str = "ababcbcddbbaabzzvmmn";
	cout << maxFreq(str) << endl;

	return 0;
}