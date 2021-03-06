#include <iostream>
#include <vector>
using namespace std;
struct node {
	int data, next;
} list[100000];
vector<int> v[3];
int main() {
	int fir, n, k, a, flag = 0;
	scanf("%d%d%d", &fir, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		scanf("%d%d", &list[a].data, &list[a].next);
	}
	for (int p = fir; p != -1; p = list[p].next) {
		int data = list[p].data;
		if (data < 0) v[0].push_back(p);
		else if (data >= 0 && data <= k) v[1].push_back(p);
		else v[2].push_back(p);
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < v[i].size(); j++)
			if (flag == 0) {
				printf("%05d %d ", v[i][j], list[v[i][j]].data);
				flag = 1;
			} else printf("%05d\n%05d %d ", v[i][j], v[i][j], list[v[i][j]].data);
	printf("-1");
	return 0;
}
