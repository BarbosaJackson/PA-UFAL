#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000001

typedef long long int lli;
typedef vector<lli> vi;
lli sum[MAXN];
void crivo(vi &ans) {
	for (int i = 1; i < MAXN; i++){
		for (int j = i; j < MAXN; j += i){
			sum[j] += i;
		}
	}
	for(lli i = 0; i < MAXN; i++) {
		if(sum[i] < MAXN) ans[sum[i]] = min(ans[sum[i]], i);
	}
}

int main() {
	vi ans;
	ans.resize(MAXN, INT_MAX);
	crivo(ans);
	lli t;
	cin >> t;
	while(t--) {
		lli c;
		cin >> c;
		cout << (ans[c] == INT_MAX ? -1 : ans[c]) << endl;
	}
	return 0;
}
