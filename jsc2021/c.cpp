#include <bits/stdc++.h>
using namespace std;
#define MAXN (2 * 10 * 10 * 10 * 10 * 10)
int main() {
	int a, b, ans;
	map<int, int> countDiv;
	cin >> a >> b;
	for(int i = a; i <= b; i++)  {
		int limit = sqrt(i);
		for(int j = 2; j <= limit; j++) {
			if(i % j == 0){
				countDiv[j]++;
				if(i % (i / j) == 0 && j != (i / j))
					countDiv[i / j]++;
			}
		}
		countDiv[i]++;
	}
	ans = 1;
	for(int i = 2; i <= MAXN; i++) {
		if(countDiv[i] > 1) ans = i;
	}
	cout << ans << endl;
	return 0;
}
