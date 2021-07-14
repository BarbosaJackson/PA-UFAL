#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, d;
	int mx = -200000;
	cin >> a >> b >> c >> d;
	for(int x = a; x <= b; x++) {
		for(int y = c; y <= d; y++) {
			mx = max(mx, x - y);
		}
	}
	cout << mx << endl;
	return 0;
}
