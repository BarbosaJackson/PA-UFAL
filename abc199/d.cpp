#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef vector<vi> vvi;

#define pb push_back

vi adjList[22];
lli colors[22];
bool seen[22];
vi path;

void dfs(int u) {
	seen[u] = 1;
	path.pb(u);
	for(auto v : adjList[u]) {
		if(!seen[v])
			dfs(v);
	}
}

lli paint(lli u, lli n) {
	if(u == (lli)path.size()) return 1;
	lli ans = 0;
	lli v = path[u];
	bool c_t[] = {0, 0, 0, 0};
	for(auto w : adjList[v])
		c_t[colors[w]] = 1;
	for(int cur_color = 1; cur_color <= 3; cur_color++) {
		if(!c_t[cur_color]){
			colors[v] = cur_color;
			ans += paint(u + 1, n);
		}
	}
	colors[v] = 0;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n, m;
	cin >> n >> m;
	for(lli i = 0; i < m; i++) {
		lli ai, bi;
		cin >> ai >> bi;
		adjList[ai].pb(bi);
		adjList[bi].pb(ai);
	}
	lli ans = 1;
	for(lli i = 1; i <= n; i++) {
		if(!seen[i]){
			// cout << "i: " << i << endl;
			path.clear();
			dfs(i);
			// for(auto x : path) {
			// 	cout << x << " ";
			// }
			// cout << endl;
			colors[path[0]] = 1;
			ans *= (3 * paint(1, n));
		}
	}

	cout << ans << endl;
	return 0;
}
