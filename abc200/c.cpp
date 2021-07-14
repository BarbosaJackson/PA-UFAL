#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int main() {
	long long int n;
	cin >> n;
	map<long long int, long long int> mult;
	for(long long int i = 0; i < n; i++) {
		long long int ai;
		cin >> ai;
		mult[ai % 200]++;
	}
	long long int ans = 0;
	for(auto &v : mult) {
		ans += ((v.se *(v.se - 1)) / 2);
	}
	cout << ans << endl;
	return 0;
}
