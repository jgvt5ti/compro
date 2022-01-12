#include <bits/stdc++.h>
using namespace std;

vector<int> e[114514];
int color[114514] = {}; // 0:white 1:gray 2:black
int ans[114514];
int cnt	  = 0;
int valid = true; // ループが存在しない

void dfs(int v) {
	color[v] = 1;
	for (int i = 0; i < e[v].size(); i++) {
		int v2 = e[v][i];
		if (color[v2] == 0) {
			dfs(v2);
		}
		if (color[v2] == 1) {
			valid = false;
			return;
		}
	}
	ans[v]	 = cnt++;
	color[v] = 2;
}

// 計算量：O(V + E)
void sort() {
	int n = 114514; // 頂点数
	for (int i = 0; i < n; i++) {
		dfs(i);
	}
}