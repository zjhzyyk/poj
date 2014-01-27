#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
#define INF 10000000
typedef pair<double, int> PDI;

struct point {
	int x,y;
}p[250];

double sq(int i) { return i*i; }

double calc(int i, int j) {
	return sqrt(sq(p[i].x-p[j].x) + sq(p[i].y-p[j].y));
}

int main() {
	int pn = 0, a,b,c,d, s = 0;
	double l[250][250];
	memset(l, 0, sizeof(l));
	priority_queue<PDI, vector<PDI>, greater<PDI> > pq;
	cin >> a >> b >> c >> d;
	p[pn].x = a; p[pn].y=b; p[pn+1].x=c; p[pn+1].y=d;
	l[pn][pn+1] = calc(pn, pn+1);
	l[pn+1][pn] = calc(pn, pn+1);
	pn+=2;
	while (cin >> a && a!=-1) {
		s = pn;
		while (cin>>b && a!=-1 && b!=-1) {
			p[pn].x = a; p[pn++].y = b;
			for (int i = 0; i<pn; i++) {
				if  (i==(pn-2) && i>=s) {
					l[i][pn-1] = calc(i, pn-1)/4.0;
					l[pn-1][i] = calc(i, pn-1)/4.0;
				}
				else {
					l[i][pn-1] = calc(i, pn-1);
					l[pn-1][i] = calc(i, pn-1);
				}
			}
			cin >> a;
		}
	}
	vector<double> dist(pn, INF);
	pq.push(make_pair(0,0));
	dist[0] = 0;
	while (!pq.empty())
	{
		PDI tmp = pq.top();
		if (tmp.second == 1) break;
		pq.pop();
		int here = tmp.second;
		for (int i = 0; i<240; i++) {
			if (l[here][i]!=0 && dist[here]+l[here][i]<dist[i]) {
				dist[i] = dist[here]+l[here][i];
				pq.push(make_pair(dist[i], i));
			}
		}
	}
	cout.setf(ios::fixed);
	cout.precision(0);
	cout << (60*dist[1]/10000) << endl;
	//system("PAUSE");
	return 0;
}
