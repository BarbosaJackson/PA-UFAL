#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while(q--) {
  	int n, ans = 0;
  	cin >> n;
  	for(char c = '1'; c <= '9'; c++) {
  		for(int digits = 1; digits <= 9; digits++) {
  			if(stoll(string(digits, c)) <= n) ans++;
  		}
  	}
  	cout << ans << endl;
  }
  return 0;
}
