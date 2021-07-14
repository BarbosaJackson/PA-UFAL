#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli table_values[6] = {0,   999, 999999, 999999999, 999999999999, 999999999999999};
lli multiply[6] = {    0,     1,      2,         3,            4, 5};
lli len_base[6] = {    3,     6,      9,        12,           15, 18};

lli count_commas(lli value, lli len) {
	if(len <= 3) return 0;
	if(len <= 6) return value - 999 + count_commas(999, len - 3);
	else if(len <= 9) return ((value - 999999) * 2) + count_commas(999999, len - 3);
	else if(len <= 12) return ((value - 999999999) * 3) + count_commas(999999999, len - 3);
	else if(len <= 15) return ((value - 999999999999) * 4) + count_commas(999999999999, len - 3);
	else return ((value - 999999999999999) * 5) + count_commas(value - 1, len - 3);
}

int main() {
	lli num;
	cin >> num;
	cout << count_commas(num, to_string(num).length()) << endl;
	return 0;
}
