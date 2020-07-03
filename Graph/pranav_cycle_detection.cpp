#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N];
bool cycle;

// if cycle is found at leasst once
// then global variable will be one
// for undirected graph
void dfs(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) {
			// not visited node,
			// that means a child node
			dfs(x, cur);
		}
		else if (x != par) {
			// this means an edge pointing to ancester
			// backedge found
			cycle = 1;
		}
	}
}

// 0 -> not visites
// 1 -> visited and in call stack
// 2 -> visited and not in call stack

void dfs_directed(int cur) {
	// inside my call stack
	vis[cur] = 1;

	for (auto x : gr[cur]) {
		if (vis[x] == 0) {
			dfs_directed(x);
		}
		else if (vis[x] == 1) {
			// in call stack
			cycle = 1;
		}
	}

	vis[cur] = 2;
	// popped out from my call stack
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
	// nodes,edges
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		// gr[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) dfs_directed(i);
	}
	cout << (cycle ? "Cycle found" : "Not found");
}
