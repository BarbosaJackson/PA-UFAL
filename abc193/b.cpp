#include <bits/stdc++.h>
using namespace std;
#define INF 1 << 30
int main() {
	long long int n;
	cin >> n;
	vector<long long> a, p, x;
	a.resize(n), p.resize(n), x.resize(n);
	long long best = INF;
	for(long long int i  = 0; i < n; i++) {
		cin >> a[i] >> p[i] >> x[i];
		if(x[i] - a[i] > 0) {
			if(best > p[i]) {
				best = p[i];
			}
		}
	}
	if(best == INF) {
		cout << "-1" << endl;
	} else {
		cout << best << endl;
	}

	return 0;
}
