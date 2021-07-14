#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	lli n, q;
	string s;
	cin >> n;
	cin >> s;
	cin >> q;
	bool flip = false;
	while(q--) {
		int t;
		lli a, b;
		cin >> t >> a >> b;
		a--, b--;
		if(t == 1){
			if(flip) {
				a = (a + n) % (2 * n);
				b = (b + n) % (2 * n); 
			} 
			char ch = s[a];
			s[a] = s[b];
			s[b] = ch;
		} else {
			flip = !flip;
		}
	}
	if(flip) {
		for(int i = 0; i < n; i++){
			char ch = s[i];
			s[i] = s[i + n];
			s[i + n] = ch;
		}
	}
	cout << s << endl;
	return 0;
}
