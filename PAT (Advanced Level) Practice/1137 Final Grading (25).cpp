#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
struct node {
	string id;
	int gp, gm, gf, g;
};
bool cmp(node &a, node &b) {
	return a.g != b.g ? a.g > b.g : a.id < b.id;
}
unordered_map<string, int> idx;
int main() {
	int p, m, n, score, cnt = 1;
	cin >> p >> m >> n;
	vector<node> v, ans;
	string s;
	while (p--) {
		cin >> s >> score;
		if (score >= 200) {
			v.push_back(node{s, score, -1, -1, 0});
			idx[s] = cnt++;
		}
	}
	while (m--) {
		cin >> s >> score;
		if (idx[s] != 0) v[idx[s]-1].gm = score;
	}
	while (n--) {
		cin >> s >> score;
		if (idx[s] != 0) {
			int tmp = idx[s] - 1;
			v[tmp].gf = v[tmp].g = score;
			if (v[tmp].gm > v[tmp].gf) v[tmp].g = (int)round(0.4 * v[tmp].gm + 0.6 * v[tmp].gf);
		}
	}
	for (int i = 0; i < v.size(); i++)
		if (v[i].g >= 60) ans.push_back(v[i]);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
		printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
	return 0;
}
