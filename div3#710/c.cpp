#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		cin >> a;
		cin >> b;
		int size_a = (int)a.size();
		int size_b = (int)b.size();
		int ans = 0;
		for(int i = 0; i < size_a; i++) {
			for(int j = 0; j < size_b; j++) {
				int k = 0;
				while(i + k < size_a && j + k < size_b) {
					if(a[i + k] != b[j + k]) {
						break;
					}
					ans = max(ans, k + 1);
					k++;
				}
			}
		}
		cout << (size_a + size_b - (2 * ans)) << endl;
	}
	return 0;
}
