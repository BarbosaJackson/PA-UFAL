#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<int> sheeps;
  for(int i = 0; i < n; i++){
    if(s[i] == '*') {
      sheeps.push_back(i);
    }
  }
  long long int ans = 0;
  int sz = sheeps.size();
  if(sz > 0) {
    int mid = sz / 2;
    int idx = sheeps[mid];
    for(int i = mid; i >= 0; i--) {
      ans += abs(idx - sheeps[i]);
      idx--;
    }
    mid = sheeps.size() / 2;
    idx = sheeps[mid];
    for(int i = mid; i < sz; i++) {
      ans += abs(idx - sheeps[i]);
      idx++;
    }
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
