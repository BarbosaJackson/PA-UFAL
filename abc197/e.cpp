#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

#define MAXN (2 * 10 * 10 * 10 * 10 * 10) + 7
#define INF LONG_LONG_MAX
typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

lli dp[1001001][2];

lli solve(lli c, lli d, vii &x) {
	if(c >= (lli)x.size()) return 0;
	if(dp[c][d] == -1) {
		lli pos = d ? x[c - 1].se : x[c - 1].fi;
		lli rg = abs(pos - x[c].se) + (x[c].se - x[c].fi);
		lli lf = abs(pos - x[c].fi) + (x[c].se - x[c].fi);
		dp[c][d] = min(
			solve(c + 1, 0, x) + rg,
			solve(c + 1, 1, x) + lf
		);
	}
	return dp[c][d];
}

int main() {
	lli n;
	vii x;
	vi l, r;
	cin >> n;
	l.resize(n, INF);
	r.resize(n, -1 * INF);
	for(lli i = 0; i < n; i++) {
		lli xi, ci;
		cin >> xi >> ci;
		ci--;
		l[ci] = min(l[ci], xi);
		r[ci] = max(r[ci], xi);
	}
	x.pb({0, 0});
	for(lli i = 0; i < n; i++) {
		if(l[i] != INF) {
			x.pb({l[i], r[i]});
		}
	}
	x.pb({0, 0});
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0, x) << endl;
	return 0;
}
