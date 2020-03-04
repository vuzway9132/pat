#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int getSum(int num) {
	int sum = 0;
	do {
		sum += num % 10;
		num /= 10;
	} while (num);
	return sum;
}
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int gcd(int a, int b) {
	return !b ? a: gcd(b, a % b);
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int k, m;
		scanf("%d%d", &k, &m);
		vector<pair<int, int>> ans;
		int begin = pow(10, k-1), end = pow(10, k);
		for (int j = begin + 9; j < end; j += 10) {
			if (getSum(j) != m) continue;
			int n = getSum(j + 1);
			int d = gcd(m, n);
			if (d > 2 && isprime(d)) ans.push_back({n, j});
		}
		sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.first != b.first ? a.first < b.first : a.second < b.second;
		});
		printf("Case %d\n", i);
		if (ans.empty()) printf("No Solution\n");
		for (auto it : ans) printf("%d %d\n", it.first, it.second);
	}
	return 0;
}
