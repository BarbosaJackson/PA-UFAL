#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	long long ans;
	cin >> n;
	vector<long long> a, b;
	a.resize(n), b.resize(n);
	for(int i =0 ;i < n; i++) {
		cin >> a[i] >> b[i];
		ans = (i == 0 ? a[i] + b[i] : min(a[i] + b[i], ans));
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			long long mx = min(max(a[i], b[j]), max(b[i], a[j]));
			ans = min(mx, ans);
		}
	}
	cout << ans << endl;
	return 0;
}
