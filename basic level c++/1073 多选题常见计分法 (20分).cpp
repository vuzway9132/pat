#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, optnum, truenum, tmp, maxcnt = 0;
	int h[] = {1, 2, 4, 8, 16}, opt[1000][100] = {0};
	char c;
	scanf("%d %d", &n, &m);
	vector<int> tot(m), right(m);
	vector<vector<int>> cnt(m, vector<int>(5));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &tot[i], &optnum, &truenum);
		for (int j = 0; j < truenum; j++) {
			scanf(" %c", &c);
			right[i] += h[c-'a'];
		}
	}
	for (int i = 0; i < n; i++) {
		double grade = 0;
		for (int j = 0; j < m; j++) {
			getchar();
			scanf("(%d", &tmp);
			for (int k = 0; k < tmp; k++) {
				scanf(" %c)", &c);
				opt[i][j] += h[c-'a'];
			}
			int exor = opt[i][j] ^ right[j];
			if (!exor) grade += tot[j];
			else {
				if ((opt[i][j] | right[j]) == right[j]) grade += 0.5 * tot[j];
				for (int k = 0; k < 5; k++)
					if (exor & h[k]) cnt[j][k]++;
			}
		}
		printf("%.1f\n", grade);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 5; j++)
			maxcnt = max(maxcnt, cnt[i][j]);
	if (maxcnt == 0) printf("Too simple\n");
	else
		for (int i = 0; i < m; i++)
			for (int j = 0; j < cnt[i].size(); j++)
				if (maxcnt == cnt[i][j]) printf("%d %d-%c\n", maxcnt, i+1, 'a'+j);
	return 0;
}
