#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, int radix) {
	long long sum = 0;
	for (int i = 0; i < n.length(); i++)
		sum = sum*radix + (isdigit(n[i]) ? n[i]-'0' : n[i]-'a'+10);
	return sum;
}
long long find_radix(string n, long long num) {
	char it = *max_element(n.begin(), n.end());
	long long low = (isdigit(it) ? it-'0' : it-'a'+10) + 1;
	long long high = max(num, low);
	while (low <= high) {
		long long mid = (low + high)/2;
		long long t = convert(n, mid);
		if (t < 0 || t > num) high = mid-1;
		else if (t == num) return mid;
		else low = mid + 1;
	}
	return -1;
}
int main() {
	string n1, n2;
	int tag = 0, radix = 0, result_radix;
	cin >> n1 >> n2 >> tag >> radix;
	result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
	if (result_radix != -1) printf("%d", result_radix);
	else printf("Impossible");
	return 0;
}
