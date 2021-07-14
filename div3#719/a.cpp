#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while(q--) {
  	string s;
  	int n;
  	cin >> n >> s;
  	int code[27];
  	memset(code, -1, sizeof(code));
  	bool flag = true;
  	for(int i = 0; i < n; i++) {
  		if(!(code[s[i] - 'A'] == -1 || code[s[i] - 'A'] == i - 1)) {
  			flag = false;
  		}
  		code[s[i] - 'A'] = i;
  	}
  	cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
