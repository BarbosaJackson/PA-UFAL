#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	lli n;
	cin >> n;
	set<lli> s;
	for(lli i = 1; i <= 1e6; i++) {
		string cur = to_string(i);
		cur += to_string(i);
		s.insert(atoll(cur.c_str()));
	}
	lli cnt = 0;
	for(auto x : s) {
		if(n < x) break;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
