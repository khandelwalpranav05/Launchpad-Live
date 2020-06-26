#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	map<int, int> mp;

	// 1 x
	// insert x
	// 2 x
	// remove x;
	// 3 x
	// tell whether
	// inside the set

	int m;
	cin >> m;

	while (m--) {
		int tp, x;
		cin >> tp >> x;
		if (tp == 1) {
			mp[x]++;
		}
		else if (tp == 2) {
			mp[x]--;
			if (mp[x] == 0) {
				mp.erase(x);
			}
		}
		else {
			if (mp.count(x)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

}
