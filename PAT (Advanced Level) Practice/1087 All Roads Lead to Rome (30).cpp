#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 0x2fffffff;
int n, k, maxvalue = 0, mindepth = inf, cntpath = 0, e[205][205], weight[205], dis[205];
double maxavg;
bool vis[205];
vector<int> pre[205], tmppath, path;
map<string, int> s2i;
map<int, string> i2s;
void dfs(int v) {
	tmppath.push_back(v);
	if (v == 1) {
		int value = 0;
		for (int i = 0; i < tmppath.size(); i++)
			value += weight[tmppath[i]];
		double tmpavg = 1.0 * value / (tmppath.size()-1);
		if (value > maxvalue) {
			maxvalue = value;
			maxavg = tmpavg;
			path = tmppath;
		} else if (value == maxvalue && tmpavg > maxavg) {
			maxavg = tmpavg;
			path = tmppath;
		}
		tmppath.pop_back();
		cntpath++;
		return ;
	}
	for (int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
	tmppath.pop_back();
}
int main() {
	fill(e[0], e[0] + 205 * 205, inf);
	fill(dis, dis + 205, inf);
	string s, sa, sb;
	int hap;
	cin >> n >> k >> s;
	s2i[s] = 1;
	i2s[1] = s;
	for (int i = 1; i < n; i++) {
		cin >> s >> weight[i + 1];
		s2i[s] = i + 1;
		i2s[i + 1] = s;
	}
	for (int i = 0; i < k; i++) {
		cin >> sa >> sb >> hap;
		e[s2i[sa]][s2i[sb]] = e[s2i[sb]][s2i[sa]] = hap;
	}
	dis[1] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 1; v <= n; v++)
			if (!vis[v] && e[u][v] != inf) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + e[u][v])
					pre[v].push_back(u);
			}
	}
	int rom = s2i["ROM"];
	dfs(rom);
	printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
	for (int i = path.size()-1; i >= 1; i--) printf("%s->", i2s[path[i]].c_str());
	printf("ROM");
	return 0;
}
