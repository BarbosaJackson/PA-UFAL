#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	bool flip = false;
	int sz = s.size();
	list <char> t;
	for(int i = 0; i < sz; i++) {
		if(s[i] == 'R') flip = !flip;
		else {
			if(flip) {
				if(t.front() == s[i]) t.pop_front();
				else t.push_front(s[i]);
			} else {
				if(t.back() == s[i]) t.pop_back();
				else t.push_back(s[i]);
			}
		}
	}
	string t_final = "";
	for(auto ti : t){
		t_final  += ti;
	}
	if(flip) {
		reverse(t_final.begin(), t_final.end());
	}
	string ans = "";
	sz = t_final.size();
	for(int i = 0; i < t_final.size(); i++) {
		int j = i;
		while(j + 1 < sz && t_final[i] == t_final[j + 1])
			j++;
		if((j - i + 1) & 1)
			ans += t_final[i];
		i = j;
	}
	cout << ans << endl;
	return 0;
}
