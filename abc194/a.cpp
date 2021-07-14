#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,ans=4;
	cin >> a >> b;
	a += b;
	if(a >= 15 && b >= 8) ans = 1;
	else if(a >= 10 && b >= 3) ans = 2;
	else if(a >= 3) ans = 3;
	cout << ans << endl;
	return 0;
}
