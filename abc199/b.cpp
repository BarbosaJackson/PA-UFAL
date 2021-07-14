#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, inf, sup;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		inf = (i == 0 ? ai : max(inf, ai));
	}
	for(int i = 0; i < n; i++) {
		int bi;
		cin >> bi;
		sup = (i == 0 ? bi : min(sup, bi));
	}
	cout << max(0, sup - inf + 1) << endl;
	return 0;
}
