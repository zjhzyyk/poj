#include <cstdio>
#include <queue>
#include <utility>
#include <functional>
#include <iostream>
#include <cstring>
using namespace std;
const int INF = 2000000000;
typedef pair<int,int> PII;

int n, r, ei, le[5005], d[2][5005];

struct edge {
	int to, w, next;
}to[200005];

void dijkstra(int st, int ed, int tp) {
	PII tmp;
	int here, v, w;
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	pq.push(make_pair(0,st));
	d[tp][st] = 0;
	while (!pq.empty()) {
		tmp = pq.top();
		here = tmp.second;
		if (here == ed) break;
		pq.pop();
		for (int i = le[here]; i!=0; i=to[i].next) {
			v = to[i].to; 
			w = to[i].w;
			if (d[tp][here] + w < d[tp][v]) {
				d[tp][v] = d[tp][here] + w;
				pq.push(make_pair(d[tp][v], v));
			}
		}
	}
}

int main() {
	cin >> n >> r;
	int a, b, di, shortest, second;
	PII tmp;
	ei = 1;
	memset(le, 0, sizeof(le));
	while (r--) {
		cin >> a >> b >> di;
		to[ei].to = b;
		to[ei].next = le[a];
		to[ei].w = di;
		le[a] = ei++;
		to[ei].to = a;
		to[ei].next = le[b];
		to[ei].w = di;
		le[b] = ei++;
	}
	for (int i = 0; i<n+2;i++) {
		d[0][i] = INF;
		d[1][i] = INF;
	}
	dijkstra(1, n, 0);
	dijkstra(n, 1, 1);
	shortest = d[0][n];
	second = INF;
	for (int i = 1; i<=n; i++) {
		for (int j = le[i]; j!=0; j = to[j].next) {
			if (d[0][i]!=INF && d[1][to[j].to]!= INF && (d[0][i] + d[1][to[j].to] + to[j].w) < second && (d[0][i] + d[1][to[j].to] + to[j].w) > shortest) 
				second = (d[0][i] + d[1][to[j].to] + to[j].w);
		}
	}
	if (second == INF) cout << shortest<<endl;
	else cout << second << endl;
	//system("PAUSE");
	return 0;
}