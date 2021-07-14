#include <bits/stdc++.h>
using namespace std;
int main() {
	string base = "ZONe", s;
	cin >> s;
	int sz = s.size(), qnt = 0;
	for(int i = 0; i < sz; i++) {
		qnt += (s.substr(i, 4) == base);
	}
	cout << qnt << endl;
	return 0;
}
