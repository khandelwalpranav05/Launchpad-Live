#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N];
int colour[N];

void dfs(int cur, int component_number) {
	vis[cur] = 1;
	colour[cur] = component_number;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x, component_number);
	}
}

int main()
{
	//  code starts
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	int connected_components = 0;

	for (int i = 1; i <= n; i++) {
		// if i is not visited
		if (vis[i] == 0) {
			dfs(i, ++connected_components);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << i << " " << colour[i] << '\n';
	}

	// cout << connected_components;

}
