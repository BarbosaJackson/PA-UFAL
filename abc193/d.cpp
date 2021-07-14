#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector<lli> vi;

lli getScore(vi &p) {
	lli score = 0;
	for(int i = 1; i <= 9; i++) {
		score += (i * pow(10, p[i]));
	}
	return score;
}

int main() {
	vi aoki, taka, dispo_cards;
	lli k;
	string cards_aoki, cards_taka;
	aoki.resize(10);
	taka.resize(10);
	dispo_cards.resize(10);
	cin >> k;
	cin >> cards_taka >> cards_aoki;
	for(int i = 1; i < 10; i++) {
		dispo_cards[i] = k;
	}
	for(int i = 0; i < 4; i++) {
		dispo_cards[cards_taka[i] - '0']--;
		dispo_cards[cards_aoki[i] - '0']--;
		aoki[cards_aoki[i] - '0']++;
		taka[cards_taka[i] - '0']++;
	}
	lli score_taka, score_aoki, wins = 0, total = 0;
	for(int i = 1; i <= 9; i++) {
		if(dispo_cards[i]) {
			taka[i]++;
			score_taka = getScore(taka);
			for(int j = 1; j <= 9; j++) {
				if(i != j || dispo_cards[i] > 1) {
					aoki[j]++;
					score_aoki = getScore(aoki);
					lli qnt_wins = 0;
					if(i == j) {
						qnt_wins = dispo_cards[i] * (dispo_cards[i] - 1);
					} else {
						qnt_wins = dispo_cards[i] * dispo_cards[j];
					}
					if(score_taka > score_aoki) {
						wins += qnt_wins;
					}
					total += qnt_wins;
					aoki[j]--;
				}
			}
			taka[i]--;
		}
	}
	long double ans = (((long double)wins) / total);
	cout <<  ans << endl;

	return 0;
}
