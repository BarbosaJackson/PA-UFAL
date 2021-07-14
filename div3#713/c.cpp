#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, size_s;
		string s;
		cin >> a >> b;
		cin >> s;
		size_s = (int)s.size();
		for(int i = 0; i < size_s; i++) {
			if(s[i] == '0') a--;
			if(s[i] == '1') b--;
		}
		int l = 0, r = size_s - 1;
		while(l < r) {
			if(s[l] != '?' && s[r] == '?') {
				s[r] = s[l];
				if(s[l] == '0') a--;
				if(s[l] == '1') b--;
			} else if(s[l] == '?' && s[r] != '?') {
				s[l] = s[r];
				if(s[r] == '0') a--;
				if(s[r] == '1') b--;
			}
			l++;
			r--;
		}
		l = 0, r = size_s - 1;
		// cout << a << " " << b << endl;
		while(l < r) {
			if(s[l] == '?' && s[r] == '?') {
				if(a > b && a >= 2) {
					s[l] = s[r] = '0';
					a -= 2;
				} else if(b >= a && b >= 2) {
					s[l] = s[r] = '1';
					b -= 2;
				}
			}
			l++;
			r--;
		}
		int mid = size_s / 2;
		if(size_s & 1 && s[mid] == '?') {
			if(a) {
				s[mid] = '0';
				a--;
			} else {
				s[mid] = '1';
				b--;
			}
		}
		// cout << s << endl;
		if(a != 0 || b != 0) s = "-1";
		for(l = 0, r = size_s - 1; l < r && s != "-1"; l++, r--) {
			if(s[l] != s[r] || s[l] == '?' || s[r] == '?')
				s = "-1";
		}
		cout << s << endl;
	}
	return 0;
}
