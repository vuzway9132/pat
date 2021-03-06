#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 999999999;
int n, m, k, ds, e[1020][1020], dis[1020];
bool vis[1020];
int main() {
	fill(e[0], e[0] + 1020 * 1020, inf);
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	int a, b, tmpdis;
	string s, t;
	for (int i = 0; i < k; i++) {
		cin >> s >> t >> tmpdis;
		a = s[0] == 'G' ? n + stoi(s.substr(1)) : stoi(s);
		b = t[0] == 'G' ? n + stoi(t.substr(1)) : stoi(t);
		e[a][b] = e[b][a] = tmpdis;
	}
	int ansid = -1;
	double ansdis = -1, ansaver = inf;
	for (int idx = n+1; idx <= n+m; idx++) {
		double mindis = inf, aver = 0;
		fill(dis, dis + 1020, inf);
		fill(vis, vis + 1020, false);
		dis[idx] = 0;
		for (int i = 1; i <= n+m; i++) {
			int u = -1, minn = inf;
			for (int j = 1; j <= n+m; j++)
				if (!vis[j] && dis[j] < minn) {
					u = j;
					minn = dis[j];
				}
			if (u == -1) break;
			vis[u] = true;
			for (int v = 1; v <= n+m; v++)
				if (!vis[v] && e[u][v] != inf && dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
		}
		for (int i = 1; i <= n; i++) {
			if (dis[i] > ds) {
				mindis = inf;
				break;
			}
			if (dis[i] < mindis) mindis = dis[i];
			aver += 1.0 * dis[i];
		}
		if (mindis == inf) continue;
		aver /= n;
		if (mindis > ansdis) {
			ansid = idx;
			ansdis = mindis;
			ansaver = aver;
		} else if (mindis == ansdis && aver < ansaver) {
			ansid = idx;
			ansaver = aver;
		}
	}
	if (ansid == -1) printf("No Solution");
	else printf("G%d\n%.1f %.1f", ansid-n, ansdis, ansaver);
	return 0;
}
