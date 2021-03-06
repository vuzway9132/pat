#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int data, l, r;
};
int n, cnt = 0;
vector<node> bst;
vector<int> in, lev;
void inOrder(int idx) {
	if (idx == -1) return;
	inOrder(bst[idx].l);
	bst[idx].data = in[cnt++];
	inOrder(bst[idx].r);
}
void bfs(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int t = q.front();
		lev.push_back(bst[t].data);
		q.pop();
		if (bst[t].l != -1) q.push(bst[t].l);
		if (bst[t].r != -1) q.push(bst[t].r);
	}
}
int main() {
	cin >> n;
	bst.resize(n), in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d%d", &bst[i].l, &bst[i].r);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	sort(in.begin(), in.end());
	inOrder(0);
	bfs(0);
	for (int i = 0; i < n; i++) {
		if (i != 0) printf(" ");
		printf("%d", lev[i]);
	}
	return 0;
}
