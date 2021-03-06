#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int vis[10000], minCnt, minTrans, src, dest;
unordered_map<int, int> line;
vector<int> path, tmpPath;
int transCnt(vector<int> &a) {
	int cnt = -1, preLine = 0;
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i-1]*10000 + a[i]] != preLine) cnt++;
		preLine = line[a[i-1]*10000 + a[i]];
	}
	return cnt;
}
void dfs(int idx, int cnt) {
	tmpPath.push_back(idx);
	vis[idx] = 1;
	if (idx == dest) {
		if (cnt < minCnt || (cnt == minCnt && transCnt(tmpPath) < minTrans)) {
			minCnt = cnt;
			minTrans = transCnt(tmpPath);
			path = tmpPath;
		}
		tmpPath.pop_back();
		vis[idx] = 0;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++)
		if (!vis[v[idx][i]]) dfs(v[idx][i], cnt+1);
	tmpPath.pop_back();
	vis[idx] = 0;
}
int main() {
	int n, m, k, pre, sid;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &m, &pre);
		for (int j = 1; j < m; j++) {
			scanf("%d", &sid);
			v[pre].push_back(sid);
			v[sid].push_back(pre);
			line[pre*10000 + sid] = line[sid*10000 + pre] = i + 1;
			pre = sid;
		}
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &src, &dest);
		minCnt = minTrans = 0x2fffffff;
		tmpPath.clear();
		dfs(src, 0);
		printf("%d\n", minCnt);
		int preLine = 0, preTrans = src;
		for (int i = 1; i < path.size(); i++)
			if (line[path[i-1]*10000 + path[i]] != preLine) {
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTrans, path[i-1]);
				preLine = line[path[i-1]*10000 + path[i]];
				preTrans = path[i-1];
			}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTrans, dest);
	}
	return 0;
}
