#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long int lli;

lli dx[4] = {0, 1, 0, -1};
lli dy[4] = {1, 0, -1, 0};

bool inside(lli x, lli y, lli h, lli w) {
	return x >= 0 && x < h && y >= 0 && y < w;
}

int main() {
	lli h, w, x, y, ans = 1;
	vector<string> s;
	cin >> h >> w >> x >> y;
	x--;
	y--;
	for(int i = 0; i < h; i++) {
		string str;
		cin >> str;
		s.pb(str);
	}
	for(int i = 0; i < 4; i++) {
		lli xi = x;
		lli yi = y;
		while(inside(xi + dx[i], yi + dy[i], h, w) && s[xi + dx[i]][yi + dy[i]] == '.'){
			ans++;
			xi += dx[i];
			yi += dy[i];
		}
	}
	cout << ans << endl;
	return 0;
}
