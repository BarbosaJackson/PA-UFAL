#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long int lli;
typedef vector<lli> vi;

int solve(lli curPos, vi &a, lli curOr, lli curXor) {
	if(curPos == (lli)a.size()) return curXor ^ curOr;
	return min(solve(curPos + 1, a, 0, curXor ^ (curOr | a[curPos])), solve(curPos + 1, a, curOr | a[curPos], curXor));
}

int main() {
	lli n;
	vi a;
	cin >> n;
	for(int i = 0; i < n; i++) {
		lli x;
		cin >> x;
		a.pb(x);
	}
	cout << solve(0, a, 0, 0) << endl;
	return 0;
}
