#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define INF 1e9

int main() {
	lli n, a, t, q, x, mx = INF, mn = -INF, base_value = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> t;
		if(t == 1) {
			base_value += a;
			mx += a;
			mn += a;
		} else if(t == 2) {
			mx = max(mx, a);
			mn = max(mn, a);
		} else {
			mn = min(mn, a);
			mx = min(mx, a);
		}
	}
	cin >> q;
	while(q--) {
		cin >> x;
		cout << max(mn, min(mx, x + base_value)) << endl;;
	}
	return 0;
}
