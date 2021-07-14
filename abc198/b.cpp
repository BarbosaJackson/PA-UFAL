#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int size_s = (int)s.size();
	int l_zero = 0, r_zero = 0;
	for(int i = 0; i < size_s; i++) {
		if(s[i] == '0') {
			l_zero++;
		} else {
			break;
		}
	}
	for(int i = size_s - 1; i >= 0; i--) {
		if(s[i] == '0') {
			r_zero++;
		} else {
			break;
		}
	}
	bool equal = true;
	for(int i = l_zero, j = size_s - r_zero - 1; i < j && equal; i++, j--) {
		if(s[i] != s[j]) {
			// cout << s[i] << " " << s[j] << endl;
			equal = false;
		}
	}
	string ans;
	// cout << equal << " " << l_zero << " " << r_zero << endl;
	if(equal && r_zero >= l_zero) ans = "Yes";
	else ans = "No";
	cout  << ans << endl;
	return 0;
}
