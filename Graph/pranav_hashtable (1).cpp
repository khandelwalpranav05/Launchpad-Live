#include<bits/stdc++.h>

using namespace std;

// asumming that key is a string
// value is a random

template<typename T>
struct node {
	string key;
	T value;
	node<T> *nxt;

	node(string _key, T _value) {
		key = _key;
		value = _value;
		nxt = NULL;
	}
};


template<typename T>
struct hashtable {
	// number of rows in bucket
	int maxSize;
	// total number of {key,value} pair inserted
	int curSize;
	node<T> **bucket;

	hashtable(int _maxSize) {
		maxSize = _maxSize;
		curSize = 0;
		bucket = new node<T>*[maxSize];
		// bucket[i] is a head of a linked list starting at i
		for (int i = 0; i < maxSize; i++) bucket[i] = NULL;
	}

	int hashfunction(string key) {
		int hash = 0;
		int p = 1;

		for (int i = 0; i < key.size(); i++) {

			hash += key[i] * p;
			hash %= maxSize;

			p *= 31;
			p %= maxSize;
		}
		// hash will remain < maxsize
		return hash;
	}


	void rehash() {
		node<T> **oldbucket = bucket;
		int oldSize = maxSize;

		curSize = 0;
		maxSize *= 2;

		bucket = new node<T>*[maxSize];
		for (int i = 0; i < maxSize; i++) bucket[i] = NULL;

		for (int i = 0; i < oldSize; i++) {
			node<T> *temp = oldbucket[i];

			while (temp != NULL) {
				insert(temp->key, temp->value);
				temp = temp->nxt;
			}
		}

		// delete the old bucket
		delete [] oldbucket;
	}


	void insert(string key, T value) {

		double load_factor = (double)curSize / maxSize;

		if (load_factor > 0.7) {
			rehash();
		}

		int index = hashfunction(key);

		node<T> *n = new node<T> (key, value);
		n->nxt = bucket[index];
		bucket[index] = n;

		curSize++;
		return ;
	}

	// pointer
	T* search(string key) {
		int index = hashfunction(key);

		node<T> *temp = bucket[index];
		while (temp != NULL) {
			if (temp->key == key) {
				return &(temp->value);
			}
			temp = temp->nxt;
		}
		return NULL;
	}

	void remove(string key) {
		int index = hashfunction(key);

		node<T> *temp = bucket[index];
		// not present
		if (temp == NULL) return;
		// check for head
		if (temp->key == key) {
			bucket[index] = bucket[index]->nxt;
			return;
		}
		while (temp->nxt != NULL) {
			if (temp->nxt->key == key) {
				temp->nxt = temp->nxt->nxt;
				return;
			}
			temp = temp->nxt;
		}
		return;
	}



};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	hashtable<int> H(3000);
	// cout << H.hashfunction("aA") << '\n';
	// cout << H.hashfunction("BB") << '\n';
	H.insert("aA", 10);
	H.insert("BB", 20);
	if (H.search("aA") != NULL) {
		cout << *H.search("aA") << '\n';
	}
	if (H.search("AAA") != NULL) {
		cout << *H.search("AAA") << '\n';
	}
	else {
		cout << "Not found\n";
	}

}
