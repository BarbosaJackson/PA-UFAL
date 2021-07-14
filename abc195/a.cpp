#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, m;
	string ans[] = {"Yes", "No"};
	cin >> m >> h;
	cout << ans[!((h % m) == 0)] << endl;
	return 0;
}
