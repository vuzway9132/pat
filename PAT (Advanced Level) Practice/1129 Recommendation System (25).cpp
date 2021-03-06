#include <iostream>
#include <set>
using namespace std;
int h[50001];
struct node {
	int v, cnt;
	bool operator < (const node &a) const {
		return cnt != a.cnt ? cnt > a.cnt : v < a.v;
	}
};
int main() {
	int n, k, num;
	scanf("%d%d", &n, &k);
	set<node> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (i != 0) {
			printf("%d:", num);
			int j = 0;
			for (auto it = s.begin(); j < k && it != s.end(); it++) {
				printf(" %d", it->v);
				j++;
			}
			printf("\n");
		}
		auto it = s.find(node{num, h[num]});
		if (it != s.end()) s.erase(it);
		s.insert(node{num, ++h[num]});
	}
	return 0;
}
