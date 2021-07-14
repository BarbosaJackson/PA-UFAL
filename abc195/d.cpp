#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;

lli dp[50][50];

lli solve(lli b, lli e, vi &boxes, vii &baggage, lli limit) {
	if(b >= boxes.size() || e >= limit) return 0;
	if(dp[b][e] == -1) {
		lli ans = solve(b + 1, e, boxes, baggage, limit);
		for(int i = e; i < limit; i++) {
			if(baggage[i].fi > boxes[b])
				continue;
			ans = max(ans, baggage[i].se + solve(b + 1, i + 1, boxes, baggage, limit));
		}
		dp[b][e] = ans;
	}
	return dp[b][e];
}

int main() {
	vii baggage;
	vi x;
	lli n, m, q;
	cin >> n >> m >> q;
	for(lli i = 0; i < n; i++) {
		lli wi, vi;
		cin >> wi >> vi;
		baggage.pb({wi, vi});
	}
	for(lli i = 0; i < m; i++) {
		lli xi;
		cin >> xi;
		x.pb(xi);
	}
	sort(baggage.begin(), baggage.end());
	DEBUG for(auto x : baggage) cout << x.fi << " " << x.se << endl;
	DEBUG cout << "----------------------------" << endl;
	while(q--) {
		lli l, r;
		cin >> l >> r;
		vi boxes;
		for(int i = 0; i < l - 1; i++) {
			boxes.pb(x[i]);
		}
		for(int i = r; i < 	m; i++) {
			boxes.pb(x[i]);
		}
		sort(boxes.begin(), boxes.end());
		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0, boxes, baggage, n) << endl;
	}
	return 0;
}
