#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int getFirst(string s, int n) {
	for(int i = 0; i < n; i++) {
		if(s[i] == '*') {
			return i;
		}
	}
	return -1;
}

int getLast(string s, int n) {
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '*') {
			return i;
		}
	}
	return -1;
}

int main() {
	int t, n, k;
	string s;
	cin >> t;
	while(t--) {
		cin >> n >> k >> s;
		int first = getFirst(s, n);
		int last = getLast(s, n);
		// cout << first << " " << last << endl;
		s[first] = 'x';
		s[last]  = 'x';
		int flag = first + 1;
		for(int i = first; i < last; i++) {
			if(s[i] == '*') {
				flag = i;
			}
			if(i - first >= k) {
				first = flag;
				s[flag] = 'x';
			}
		}
		int ans = 0;
		// cout << s << endl;
		for(int i = 0; i < n; i++)
			ans += (s[i] == 'x');
		cout << ans << endl;
	}
	return 0;
}
