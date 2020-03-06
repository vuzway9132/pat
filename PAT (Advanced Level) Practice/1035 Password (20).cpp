#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string> v;
	string s = "10lO", u, pwd;
	for (int i = 0; i < n; i++) {
		cin >> u >> pwd;
		int flag = 0;
		for (int j = 0; j < pwd.length(); j++) {
			if (s.find(pwd[j]) != string::npos) flag = 1;
			if (pwd[j] == '1') pwd[j] = '@';
			if (pwd[j] == '0') pwd[j] = '%';
			if (pwd[j] == 'l') pwd[j] = 'L';
			if (pwd[j] == 'O') pwd[j] = 'o';
		}
		if (flag == 1) v.push_back(u + " " + pwd);
	}
	if (v.size() == 0)
		printf("There %s %d account%s and no account is modified", n > 1? "are" : "is", n, n > 1 ? "s" : "");
	else {
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;
	}
	return 0;
}
