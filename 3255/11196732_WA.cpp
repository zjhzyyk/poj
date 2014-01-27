#include <cstdio>
#include <queue>
#include <utility>
#include <functional>
#include <iostream>
#include <cstring>
using namespace std;
const int INF = 2000000000;
typedef pair<int,int> PII;

int n, r, tei, fei, tle[5005], fle[5005], d1[5005], d2[5005];

struct edge {
	int to, w, next;
}to[100005], from[100005];

int main() {
	cin >> n >> r;
	int a, b, d, here, v, w, shortest, second;
	PII tmp;
	tei = fei = 1;
	memset(tle, 0, sizeof(tle));
	memset(fle, 0, sizeof(fle));
	while (r--) {
		cin >> a >> b >> d;
		to[tei].to = b;
		to[tei].next = tle[a];
		to[tei].w = d;
		tle[a] = tei++;
		from[fei].to = a;
		from[fei].next = fle[b];
		from[fei].w = d;
		fle[b] = fei++;
	}
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	for (int i = 0; i<n+2;i++) {
		d1[i] = d2[i] = INF;
	}
	pq.push(make_pair(0,1));
	d1[1] = 0;
	while (!pq.empty()) {
		tmp = pq.top();
		here = tmp.second;
		if (here == n) break;
		pq.pop();
		for (int i = tle[here]; i!=0; i=to[i].next) {
			v = to[i].to; 
			w = to[i].w;
			if (d1[here] + w < d1[v]) {
				d1[v] = d1[here] + w;
				pq.push(make_pair(d1[v], v));
			}
		}
	}
	shortest = d1[n];
	second = INF;
	while (!pq.empty()) pq.pop();
	pq.push(make_pair(0, n));
	d2[n] = 0;
	while (!pq.empty()) {
		tmp = pq.top();
		here = tmp.second;
		if (here == 1) break;
		pq.pop();
		for (int i = fle[here]; i!=0; i=from[i].next) {
			v = from[i].to; 
			w = from[i].w;
			if (d2[here] + w < d2[v]) {
				d2[v] = d2[here] + w;
				pq.push(make_pair(d2[v], v));
			}
		}
	}
	for (int i = 1; i<=n; i++) {
		for (int j = tle[i]; j!=0; j = to[j].next) {
			if ((d1[i] + d2[to[j].to] + to[j].w) < second && (d1[i] + d2[to[j].to] + to[j].w) > shortest) 
				second = (d1[i] + d2[to[j].to] + to[j].w);
		}
	}
	if (second == INF) cout << shortest<<endl;
	else cout << second << endl;
	//system("PAUSE");
	return 0;
}