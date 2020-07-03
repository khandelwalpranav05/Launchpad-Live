#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	//  code starts
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	string s[n];

	queue<pair<int, int>> Q;

	int dis[n][m];
	bool vis[n][m];
	pair<int, int> nearest_shop[n][m];

	for (int i = 0; i < n; i++) {

		cin >> s[i];

		for (int j = 0; j < m; j++) {

			dis[i][j] = INT_MAX;
			vis[i][j] = false;

			if (s[i][j] == '#') {
				dis[i][j] = 0;
				vis[i][j] = true;
				nearest_shop[i][j] = {i, j};
				Q.push({i, j});
			}

		}
	}

	while (!Q.empty()) {

		pair<int, int> tp = Q.front();
		Q.pop();
		int x = tp.first, y = tp.second;

		for (int i = 0; i < 4; i++) {

			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0) {
				// out of bound limits
				vis[xx][yy] = 1;
				dis[xx][yy] = dis[x][y] + 1;
				nearest_shop[xx][yy] = nearest_shop[x][y];
				Q.push({xx, yy});
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dis[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "{" << nearest_shop[i][j].first << "," << nearest_shop[i][j].second << "} ";
		}
		cout << '\n';
	}

}
