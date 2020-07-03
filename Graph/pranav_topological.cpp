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

vector<int> gr[N];
int vis[N];

vector<int> order;

void dfs(int cur) {
	vis[cur] = 1;

	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x);
		}
	}

	order.push_back(cur);
	return ;
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
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i);
	}

	reverse(order.begin(), order.end());

	for (auto x : order) cout << x << " ";

}
