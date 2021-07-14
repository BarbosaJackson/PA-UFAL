#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define INF 1000 * 1000 + 1
#define fi first
#define se second
int main() {
	lli a, b, w;
	pair<lli, lli> ans;
	cin >> a >> b >> w;
	w *= 1000;
	ans.fi = INF;
	ans.se = 0;
	for(lli n = 0; n < INF; n++) {
		if(a * n <= w && w <= b * n) {
			ans.fi = min(ans.fi, n);
			ans.se = max(ans.se, n);
		}
	}
	if(ans.fi == INF) {
		cout << "UNSATISFIABLE" << endl;
	} else {
		cout << ans.fi << " " << ans.se << endl;
	}
	return 0;
}
