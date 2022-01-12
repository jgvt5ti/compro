#include <bits/stdc++.h>
using namespace std;
using ll		 = long long;
using P			 = pair<int, int>;
constexpr ll INF = 1e18;

ll cost[1000];
bool used[1000] = {};

ll e[1000][1000];

int prim(int s) {
	int n, m;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cost[i] = INF;
	}
	cost[s] = 0;
	while (1) {
		int u	= -1;
		ll cmin = INF;
		for (int i = 0; i < n; i++) {
			if (!used[i] && cost[i] < cmin) {
				cmin = cost[i];
				u	 = i;
			}
		}
		if (u == -1) return;
		used[u] = true;
		ret += cmin;
		for (int i = 0; i < n; i++) {
			cost[i] = min(cost[i], e[u][i]);
		}
	}
	return ret;
}