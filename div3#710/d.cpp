#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<int, int> count;
		int mx = 0;
		for(int i = 0; i < n; i++) {
			int ai;
			cin >> ai;
			count[ai]++;
			mx = max(mx, count[ai]);
		}
		cout << (mx > n - mx ? (mx - (n - mx)) : n % 2) << endl;
	}
	return 0;
}
