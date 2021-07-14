#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << floor((z * ((double)y / x)) - 0.000001) << endl;
	return 0;
}
