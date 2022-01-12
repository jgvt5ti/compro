#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
	vector<int> par, rank, size;
	UnionFind(int n) {
		par.resize(n);
		rank.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			par[i]	= i;
			rank[i] = 1;
			size[i] = 1;
		}
	}
	int root(int i) {
		if (par[i] == i) {
			return i;
		} else {
			return root(par[i]);
		}
	}
	bool isSame(int i, int j) {
		return root(i) == root(j);
	}
	void unite(int i, int j) {
		int pi = root(i), pj = root(j);
		if (pi == pj) return;
		if (rank[pi] < rank[pj]) swap(pi, pj);
		par[pj] = pi;
		if (rank[pi] == rank[pj]) rank[pi]++;
		size[pi] += size[pj];
	}
};