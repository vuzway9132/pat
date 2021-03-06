#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, maxht = 0;
vector<vector<int>> v;
bool vis[10010];
set<int> s;
vector<int> tmp;
void dfs(int idx, int ht) {
	if (ht > maxht) {
		tmp.clear();
		tmp.push_back(idx);
		maxht = ht;
	} else if (ht == maxht)
		tmp.push_back(idx);
	vis[idx] = true;
	for (int i = 0; i < v[idx].size(); i++)
		if (!vis[v[idx][i]])
			dfs(v[idx][i], ht + 1);
}
int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	int a, b, src, cnt = 0;
	for (int i = 0; i < n-1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			dfs(i, 1);
			if (i == 1) {
				if (tmp.size() != 0) src = tmp[0];
				for (auto it : tmp) s.insert(it);
			}
			cnt++;
		}
	if (cnt > 1) printf("Error: %d components", cnt);
	else {
		tmp.clear();
		maxht = 0;
		fill(vis, vis + 10010, false);
		dfs(src, 1);
		for (auto it : tmp) s.insert(it);
		for (auto it : s) printf("%d\n", it);
	}
	return 0;
}
