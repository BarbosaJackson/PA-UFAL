#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector<double> dp;

double calc(lli cur, lli end) {
	if(cur == end) return 0;
	if(dp[cur] == -1) dp[cur] = 1.0 / ((double)(end - cur) / end) + calc(cur + 1, end);
	return dp[cur];

}

int main() {

	lli n;
	cin >> n;
	dp.resize(n, -1);
	cout <<  setprecision(15) << calc(1, n) << endl;
	return 0;
}
