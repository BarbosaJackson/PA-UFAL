#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
	vector<bool> seen; seen.resize((n * n) + 1, false);
	int c = 1;
	int n2 = n*n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << c << " ";
			seen[c] = true;
			if(i == n - 1 && j == n - 1) break;
			while(true) {
				c += 2;
				if(c > n2) c = 2;
				if(!seen[c]) break;
			}
		}
		cout << endl;
	}
} 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while(q--) {
  	int n, ans = 0;
  	cin >> n;
  	if(n == 2)
  		cout << -1 << endl;
  	else solve(n);
  }
  return 0;
}
