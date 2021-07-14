#include <bits/stdc++.h>

using namespace std;

#define pb push_back

bool check(double y, int h, int d, int n, vector<int> &di, vector<int> &hi) {
	double cof = (double)(h-y) / d;
	for(int i =0 ; i < n; i++) {
		if(di[i] * cof + y < hi[i]) return false;
	}
	return true;
}

int main() {
	int n, d, h;
	vector<int> di, hi;
	cin >> n >> d >> h;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		di.pb(a);
		hi.pb(b);
	}
	double b = 0, e = 1000;
	while(abs(e - b) > 0.0000001) {
		double mid = (b + e) / 2;
		if(check(mid, h, d, n, di, hi)) e = mid;
		else b = mid;
	}
	cout << b << endl;
	return 0;
}
