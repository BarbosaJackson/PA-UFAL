#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli, lli> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define pb push_back
#define fi first
#define se second

set<int> path;
vector<bool> visited;
map<int, int> count_colors;

void dfs(lli u, vvi &tree, vi &colors) {
	visited[u] = true;
	count_colors[colors[u]]++;
	if(count_colors[colors[u]] == 1) {
		path.insert(u);
	}
	for(auto v : tree[u]) {
		if(!visited[v]) {
			dfs(v, tree, colors);
		}
	}
	count_colors[colors[u]]--;
}

int main() {
	vvi tree;
	vi colors;
	lli n;
	cin >> n;
	tree.resize(n);
	visited.resize(n);
	for(lli i = 0; i < n; i++) {
		lli color;
		cin >> color;
		colors.pb(color);
	}
	for(lli i = 0; i < n - 1; i++) {
		lli u, v;
		cin >> u >> v;
		u--;
		v--;
		tree[u].pb(v);
		tree[v].pb(u);
	}
	dfs(0, tree, colors);
	for(auto x : path) {
		cout << (x + 1) << endl;
	}
	return 0;
}
