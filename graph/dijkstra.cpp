#include <bits/stdc++.h>
using namespace std;
using ll		 = long long;
using P			 = pair<int, int>;
constexpr ll INF = 1e18;

ll d[100000];
vector<P> e[100000];

// 計算量：O(ElogV)
void dijkstra(int n, int s) {
	for (int i = 0; i < n; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	priority_queue<P> que;
	que.emplace(0, s);
	while (!que.empty()) {
		auto &[dv, v] = que.top();
		que.pop();
		for (int i = 0; i < e[v].size(); i++) {
			auto &[cost, u] = e[v][i];
			if (d[u] > d[v] + cost) {
				d[u] = d[v] + cost;
				que.emplace(d[u], u);
			}
		}
	}
}