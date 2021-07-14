#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		vector<vector<int>> v;
		set<int> values;
		v.resize(200);

		cin >> n;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			values.insert(x);
			v[x].pb(i + 1);
		}
		for(auto k : values) {
			if((int)v[k].size() == 1) cout << v[k][0] << endl;
		}
	}
	return 0;
}
