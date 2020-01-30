#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, d = 0x3fff;
	scanf("%d%d", &n, &m);
	vector<int> sum(n+1);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(sum.begin()+i, sum.end(), sum[i-1]+m) - sum.begin();
		if (sum[j-1] - sum[i-1] == m) {
			d = m;
			break;
		} else if (j <= n && sum[j]-sum[i-1] < d)
			d = sum[j] - sum[i-1];
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(sum.begin()+i, sum.end(), sum[i-1]+d) - sum.begin();
		if (sum[j-1] - sum[i-1] == d)
			printf("%d-%d\n", i, j-1);
	}
	return 0;
}
