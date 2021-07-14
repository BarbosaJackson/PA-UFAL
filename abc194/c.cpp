#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int main() {
	long long int ans = 0, n;
	long long value;
	map<long long, long long> a;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> value;
		for(auto v : a) {
			ans += ((value - v.fi) * (value - v.fi) * v.se);
		}
		a[value]++;
	}
	cout << ans << endl;
	return 0;
}
