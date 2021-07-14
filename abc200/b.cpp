#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int n, k;
	cin >> n >> k;
	while(k--) {
		if(!(n % 200)) n /= 200;
		else n = stoll(to_string(n) + "200");
	}
	cout << n << endl;
	return 0;
}
