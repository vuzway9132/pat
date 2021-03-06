#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n, cnt = 0;
void factorization(int index, int sum) {
	if (sum > n) return;
	if (sum == n) {
		printf("%d=", n);
		for (int i = 0; i < v.size(); i++) {
			if (i != 0) printf("+");
			printf("%d", v[i]);
		}
		if (++cnt % 4 == 0 || v[v.size()-1] == n) printf("\n");
		else printf(";");
		return;
	}
	for (int j = index; j <= n; j++) {
		v.push_back(j);
		factorization(j, sum + j);
		v.pop_back();
	}
}
int main() {
	scanf("%d", &n);
	factorization(1, 0);
	return 0;
}
