#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli MOD = 1e9 + 7;
lli modPow(lli base, lli exp) {
	lli ans = 1;
	while(exp) {
		if(exp & 1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return ans;
}

int main() {
	lli n, p;
	cin >> n >> p;
	cout << (((p - 1) * modPow(p - 2, n - 1)) % MOD) << endl;
	return 0;
}
