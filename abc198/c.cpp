#include <bits/stdc++.h>
using namespace std;
double dist(double x, double y) {
	return sqrt(x * x + y * y);
}
int main() {
	double r, x, y, d;
	cin >> r >> x >> y;
	d = dist(x, y);
	long long ans = (r > d ? 2 : ceil(d / r));
	cout << ans << endl;
	return 0;
}
