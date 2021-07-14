#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 1001
int main() {
	int n, m;
	map<int, int> values;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		values[ai]++;
	}
	for(int i = 0; i < m; i++) {
		int bi;
		cin >> bi;
		values[bi]++;
	}
	for(int i = 0; i < MAXN; i++) {
		if(values[i] == 1)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}
