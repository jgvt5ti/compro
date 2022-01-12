#include <bits/stdc++.h>
using namespace std;
using ll		 = long long;
using P			 = pair<int, int>;
constexpr ll INF = 1e18;

ll d[1000];
vector<P> e[1000];

// 計算量：O(EV)
bool bellman_ford(int n, int s) {
	// 負のループが存在しないならtrue
	bool ret = true;
	for (int i = 0; i < n; i++) {
		d[i] = INF;
	}
	// 最短経路
	d[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < e[u].size(); j++) {
				int v = e[u][j].first;
				int w = e[u][j].second;
				if (d[u] != INF && d[v] > d[u] + w) {
					d[v] = d[u] + w;
				}
			}
		}
	}
	// 負閉路検出
	for (int i = 0; i < n; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < e[u].size(); j++) {
				int v = e[u][j].first;
				int w = e[u][j].second;
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					ret	 = false;
				}
			}
		}
	}
	return ret;
}