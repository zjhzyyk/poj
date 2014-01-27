#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#define INF 10000000
using namespace std;

struct point {
	int x,y;
}p[250];

double dist[250];

class cmp{
public:
	bool operator() (const int& aa, const int& bb) const {
		return dist[aa] > dist[bb];
	}
};

int sq(int i) { return i*i; }

double calc(int i, int j) {
	return sqrt(sq(p[i].x-p[j].x) + sq(p[i].y-p[j].y));
}

int main() {
	int pn = 0, tmp, a=0,b=0,c=0,d=0, s = 0;
	double l[250][250];
	bool vis[250];
	memset(l, 0, sizeof(l));
	memset(vis, 0, sizeof(vis));
//	fill(dist, dist+sizeof(dist), INF);
	for (int i = 0; i<250; i++) dist[i] = INF;
	priority_queue<int, vector<int>, cmp> pq;
	cin >> a >> b >> c >> d;
	p[pn].x = a; p[pn].y=b; p[pn+1].x=c; p[pn+1].y=d;
	l[pn][pn+1] = calc(pn, pn+1);
	l[pn+1][pn] = calc(pn, pn+1);
	pn+=2;
	while (cin >> a && a!=-1) {
		s = pn;
		while (cin>>b && a!=-1 && b!=-1) {
			p[pn].x = a; p[pn++].y = b;
			for (int i = s; i<pn; i++) {
				l[i][pn-1] = calc(i, pn-1)/4.0;
				l[pn-1][i] = calc(i, pn-1)/4.0;
			}
			for (int i = 0; i<s; i++) {
				l[i][pn-1] = calc(i, pn-1);
				l[pn-1][i] = calc(i, pn-1);
			}
			cin >> a;
		}
	}
	dist[0] = 0;
	pq.push(0);
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();
		vis[tmp] = 1;
		for (int i = 0; i<250; i++) {
			if (!vis[i] && l[tmp][i]!=0) {
				dist[i] = min(dist[i], dist[tmp]+l[tmp][i]);
				pq.push(i);
			}
		}
	}
	printf("%.0lf", 60*dist[1]/10000);
	return 0;
}
