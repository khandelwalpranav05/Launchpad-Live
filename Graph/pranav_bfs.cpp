#include<bits/stdc++.h>

using namespace std;

#define P pair<int,int>

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 1e5;

vector<int> gr[N];
int vis[N];

void bfs(int source) {
	queue<int> Q;

	Q.push(source);
	vis[source] = 1;

	while (!Q.empty()) {

		int cur = Q.front();
		Q.pop();

		cout << cur << '\n';

		for (auto x : gr[cur]) {
			if (!vis[x]) {
				vis[x] = 1;
				Q.push(x);
			}
		}

	}
}

// shortest distance from source
// node in an unweighted graph
vector<int> bfs(int source, int n) {
	vector<bool> vis(n + 1, 0);

	vector<int> dis(n + 1);

	queue<int> Q;
	Q.push(source);
	vis[source] = 1;
	dis[source] = 0;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (auto x : gr[cur]) {
			if (!vis[x]) {
				// mark it visited brfore pushing in Q
				vis[x] = 1;
				// mark the distance for the child node
				dis[x] = dis[cur] + 1;
				Q.push(x);
			}
		}
	}
	return dis;
}

vector<int> bfs(int source, int n) {
	vector<int> dis(n + 1, INT_MAX);
	queue<int> Q;
	Q.push(source);
	dis[source] = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto x : gr[cur]) {
			if (dis[x] == INT_MAX) {
				dis[x] = dis[cur] + 1;
				Q.push(x);
			}
		}
	}
	return dis;
}

int main()
{
	//  code starts
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n ;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	vector<int> dis = bfs(2, n);
}
