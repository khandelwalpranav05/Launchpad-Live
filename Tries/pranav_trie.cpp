#include<bits/stdc++.h>

using namespace std;

struct node {
	node* nxt[26];
	int is_end;
	int cntt;
	node() {
		for (int i = 0; i < 26; i++) nxt[i] = NULL;
		is_end = 0;
		cntt = 0;
	}
};

node* root;
// O(|name|)
void insert(string name) {
	node *cur = root;

	for (int i = 0; i < name.size(); i++) {
		if (cur->nxt[name[i] - 'a'] == NULL) {
			cur->nxt[name[i] - 'a'] = new node();
		}
		cur = cur->nxt[name[i] - 'a'];
		cur->cntt++;
	}
	cur->is_end++;
	return;
}

// O(|name|)
bool search(string name) {
	node *cur = root;

	for (int i = 0; i < name.size(); i++) {
		if (cur->nxt[name[i] - 'a'] == NULL) {
			return false;
		}
		cur = cur->nxt[name[i] - 'a'];
	}

	return cur->is_end;
}

// O(|name|)
int cnt(string name) {
	node *cur = root;

	for (int i = 0; i < name.size(); i++) {
		if (cur->nxt[name[i] - 'a'] == NULL) {
			return 0;
		}
		cur = cur->nxt[name[i] - 'a'];
	}

	return cur->is_end;
}

// tells total string with name as prefix
int solve(string name) {
	node *cur = root;

	for (int i = 0; i < name.size(); i++) {
		if (cur->nxt[name[i] - 'a'] == NULL) {
			return 0;
		}
		cur = cur->nxt[name[i] - 'a'];
	}
	//
	return cur->cntt;
}

int main()
{
	//  code starts
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	root = new node();

	insert("apaar");
	insert("vishal");
	insert("aryan");

	if (search("apaa")) cout << "YES";

}
