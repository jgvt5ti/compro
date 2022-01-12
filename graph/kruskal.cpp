#include <bits/stdc++.h>
using namespace std;
using ll		 = long long;
constexpr ll INF = 1e18;
vector<edge> e;

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

struct edge {
	int from, to, cost;
	bool operator<(edge e) {
		return this->cost < e.cost;
	}
};

// O(ElogE)
int kruskal() {
	int n, m; // vertex, edge
	int ret = 0;
	sort(e.begin(), e.end());
	UnionFind uf(n);
	for (int i = 0; i < m; i++) {
		int u = e[i].from, v = e[i].to;
		if (!uf.isSame(u, v)) {
			ret += e[i].cost;
			uf.unite(u, v);
		}
	}
	return ret;
}