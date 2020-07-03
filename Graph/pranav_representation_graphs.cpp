#include<bits/stdc++.h>

using namespace std;

int main()
{
	//  code starts
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// nodes,edges
	int n, m;
	cin >> n >> m;

	// array of vectors

	// vector<int> graph[n + 1];

	// // graph[0] is a vector
	// // graph[1] is a vector

	// for (int i = 0; i < m; i++) {
	// 	int x, y;
	// 	cin >> x >> y;

	// 	graph[x].push_back(y);
	// 	graph[y].push_back(x);

	// }

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << "--> ";
	// 	for (auto x : graph[i]) cout << x << " ";
	// 	cout << '\n';
	// }


	// weighted graph adjacency representation

	vector<pair<int, int>> graph[n + 1];

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		graph[x].push_back({y, w});
		graph[y].push_back({x, w});

	}

	for (int i = 1; i <= n; i++) {
		cout << i << "--> ";
		for (auto x : graph[i]) cout << "{" << x.first << "," << x.second << "} ";
		cout << '\n';
	}

}
