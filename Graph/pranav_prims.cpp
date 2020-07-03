#include<bits/stdc++.h>

using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

#define P pair<int,int>

const int N = 1e5;

vector<P> gr[N];

// mimimum spanning tree
int prims(int n) {

	vector<int> vis(n + 1, 0);
	int mst = 0;

	// {dis , node}
	priority_queue<P, vector<P>, greater<P>> Q;

	// initialised my algorithm
	Q.push({0, 1});

	while (!Q.empty()) {
		P p = Q.top();
		Q.pop();

		int cur = p.second;
		int weight_of_minimum_edge = p.first;

		if (vis[cur] == 0) {
			vis[cur] = 1;
			mst += weight_of_minimum_edge;

			for (auto x : gr[cur]) {

				int to = x.first;
				int weight = x.second;

				if (vis[to] == 0) {
					Q.push({weight, to});
				}

			}
		}
	}

	return mst;
}

int32_t main()
{
	//  code starts
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	int mst = prims(n);

}
