#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int cur, bool vis[]) {
	cout << cur << '\n';

	vis[cur] = true;

	for (auto x : adj[cur]) {

		if (vis[x] == false) {
			// goto x if it was not visited
			dfs(adj, x, vis);

		}

	}
	cout << cur << '\n';
	return;
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

	vector<int> adj[n + 1];

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int root = 1;

	bool vis[n + 1] = {};

	dfs(adj, root, vis);

}
