#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> ii;
int dist(ii p1, ii p2) {
	return sqrt(pow(p2.fi - p1.fi, 2) + pow(p2.se - p1.se, 2));
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<string> field;
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			field.pb(s);
		}
		vector<ii> p;
		for(int i = 0; i < n && (int)p.size() < 2; i++) {
			for(int j = 0; j < n && (int)p.size() < 2; j++) {
				if(field[i][j] == '*') {
					p.pb({i, j});
				}
			}
		}
		// for(auto k : p) {
		// 	cout << k.fi << " " << k.se << endl;
		// }
		int x1,x2,y1,y2;
		if(p[0].fi == p[1].fi) {
			x1 = (p[0].fi + 1 == n) ? p[0].fi - 1 : p[0].fi + 1;
			x2 = x1;
			y1 = p[0].se;
			y2 = p[1].se;
		} else if(p[0].se == p[1].se) {
			y1 = (p[0].se + 1 == n ? p[0].se - 1 : p[0].se + 1);
			y2 = y1;
			x1 = p[0].fi;
			x2 = p[1].fi;
		} else {
			vector<ii> pos;
			int dx[4] = {1, 1, 0, 0};
			int dy[4] = {0, 1, 0, 1};
			for(int i = 0; i < 4; i++) {
				int x = min(p[0].fi, p[1].fi) + abs(p[0].fi - p[1].fi) * dx[i];
				int y = min(p[0].se, p[1].se) + abs(p[0].se - p[1].se) * dy[i];
				bool new_point = true;
				for(int i = 0; i < 2; i++) {
					if(p[i].fi == x && p[i].se == y) {
						new_point = false;
					}
				}
				if(new_point)
					pos.pb({x, y});
			}
			x1 = pos[0].fi;
			x2 = pos[1].fi;
			y1 = pos[0].se;
			y2 = pos[1].se;
		}
		field[x1][y1] = '*';
		field[x2][y2] = '*';
		for(auto s : field) cout << s << endl;
	}
	return 0;
}
