#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli getI(lli x, lli n) {
	return (x - 1) / n;
}

lli getJ(lli x, lli n) {
	return (x - 1) % n;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long int n, m, x;
		cin >> n >> m >> x;
		cout << (getJ(x, n) * m) + getI(x, n) + 1 << endl;
	}
	return 0;
}
