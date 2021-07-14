	#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli dp[200][200][200][2];
lli value[200][200][200][2];
vector<lli> a, b, c;
lli solve(lli i, lli resto1, lli resto2, lli equals, lli n) {
	if(i == n) return (resto1 == resto2 && equals ? 1 : 0);
	if(dp[i][resto1][resto2][equals] != -1)
		return dp[i][resto1][resto2][equals];
	lli ans = 0;
	lli state = solve(i + 1, resto1, resto2, equals, n);
	if(state > ans) {
		value[i][resto1][resto2][equals] = 1;
		ans = 1;
	}
	state = solve(i + 1, (resto1 + a[i]) % 200, resto2, 1, n);
	if(state > ans) {
		value[i][resto1][resto2][equals] = 2;
		ans = 1;
	}
	state = solve(i + 1, resto1, (resto2 + a[i]) % 200, 1, n);
	if(state > ans) {
		value[i][resto1][resto2][equals] = 3;
		ans = 1;
	}
	state = solve(i + 1, (resto1 + a[i]) % 200, (resto2 + a[i]) % 200, equals, n);
	if(state > ans) {
		value[i][resto1][resto2][equals] = 4;
		ans = 1;
	}
	dp[i][resto1][resto2][equals] = ans;
	return ans;
}

int  main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	a.resize(n);
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int can = solve(0, 0, 0, 0, n);
	if(can) {
		for(int i = 0, resto1 = 0, resto2 = 0, equals = 0; i < n; i++) {
			if(value[i][resto1][resto2][equals] == 2) {
				resto1 = (resto1 + a[i]) % 200;
				equals = 1;
				b.push_back(i);
			} else if(value[i][resto1][resto2][equals] == 3) {
				resto2 = (resto2 + a[i]) % 200;
				equals = 1;
				c.push_back(i);
			} else {
				resto1 = (resto1 + a[i]) % 200;
				resto2 = (resto2 + a[i]) % 200;
				b.push_back(i);
				c.push_back(i);
			}
		}
		cout << "YES" << endl;
		cout << b.size() << " ";
		for(auto x : b) {
			cout << (x + 1) << " ";
		}
		cout << endl << c.size() << " ";
		for(auto y : c) {
			cout << (y + 1) << " ";
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
