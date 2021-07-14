#include <bits/stdc++.h>
using namespace std;
int main() {
	unsigned long long int n;
	cin >> n;
	// cout << n << endl;
	long long int a;
	// long long qnt = 0;
	set<long long int> v;
	for(a = 2; a * a <= n; a++) {
		long long cur_pot = a * a;
		while(cur_pot <= n) {
			// qnt++;
			v.insert(cur_pot);
			cur_pot *= a;
		}
	}
	long long int x = n - v.size();
	// cout << "n: " << n << endl;
	// cout << "size: " << v.size() << endl;
	cout << x << endl;
	return 0;
}
