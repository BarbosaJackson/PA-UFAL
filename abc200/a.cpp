#include <bits/stdc++.h>
using namespace std;
int main() {
	int year;
	cin >> year;
	cout << (year / 100 + (year % 100 ? 1 : 0)) << endl;
	return 0;
}
