#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define fi first
#define se second
#define INF 1e9
vii adjList[500 * 500];
int dist[500 * 500];
int a[500][500], b[500][500];
int n, m;

int getIndex(int i, int j) {
	return i * m + j;
}

int dijkstra(int target) {
	for(int i = 0; i < n * m; i++) {
		dist[i] = INF;
	}
	priority_queue<ii> pq;
	dist[0] = 0;
	pq.push({dist[0], 0});
	while(!pq.empty()) {
		ii top = pq.top(); pq.pop();
		int u = top.se;
		int d = -top.fi;
		if(u == target) break;
		if(d > dist[u]) continue;
		// cout << "u: " << u << " | d: " << d << endl;
		for(auto w : adjList[u]) {
			int v = w.fi;
			int d2 = w.se;
			// cout << "v: " << v << " | d2: " << d2 << endl;
			if(d + d2 < dist[v]){
				// cout << "powpowpow" << endl;
				dist[v] = d + d2;
				pq.push({-dist[v], v});
			}
		}
	}
	return dist[getIndex(n - 1, m - 1)];
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m - 1; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (j + 1 < m) adjList[getIndex(i, j)].pb({getIndex(i, j + 1), a[i][j]});
        if (j - 1 >= 0) adjList[getIndex(i, j)].pb({getIndex(i, j - 1), a[i][j - 1]});
        if (i + 1 < n) adjList[getIndex(i, j)].pb({getIndex(i + 1, j), b[i][j]});
        for (int k = 1; k <= i; k++)
          adjList[getIndex(i, j)].pb({getIndex(i - k, j), 1 + k});
		}
	}
	cout << dijkstra(getIndex(n - 1, m - 1)) << endl;
	return 0;
}
