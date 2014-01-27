#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
using namespace std;
const double eps = 1e-7;  
const int INF = 2000000000;
typedef pair<double , int > PII;

int n, pi;
double d[150][150], dist[150];
double s, yc;

struct point {
    double x, y;
    int i;
}p[150];

struct wall {
    double x, y[4];
}w[35];

int dblcmp(double a, double b) {
    if (abs(a-b) < eps) return 0;
    return (a-b)>0 ? 1 : -1;
}

void check(){
	int cnt;
    for (int k = 0; k<pi; k++) {
		cnt = 0;
        if (p[pi].x == p[k].x) d[pi][k] = d[k][pi] = abs(p[pi].y - p[k].y);
        else {
            s = (p[pi].y-p[k].y) / (double)(p[pi].x-p[k].x);
            for(int l = p[k].i+1; l<p[pi].i; l++) {
                yc = p[k].y + s * (w[l].x - p[k].x);
                if ((dblcmp(yc, w[l].y[0])>=0 && dblcmp(yc, w[l].y[1])<=0) ||
                    (dblcmp(yc, w[l].y[3]) <= 0 && dblcmp(yc, w[l].y[2])>=0))
                    cnt++;
            }
			if (cnt == p[pi].i - p[k].i - 1)
				d[pi][k] = d[k][pi] = sqrt((p[pi].x - p[k].x)*(p[pi].x - p[k].x)
                    +(p[pi].y - p[k].y)*(p[pi].y - p[k].y));
        }
    }
}

int main(){
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    p[0].x = 0;
    p[0].y = 5;
	p[0].i = -1;
    PII tmp;
    int here;
    cout.setf(ios::fixed);
    cout.precision(2);
    while (cin >> n && n!= -1) {
        pi = 1;
        for (int i = 0; i<4*n+3; i++) for (int j = 0; j<4*n+3; j++) d[i][j] = d[j][i] = INF;
        for (int i = 0; i<n; i++) {
            cin >> w[i].x;
            for (int j = 0; j<4; j++) {
                cin >> w[i].y[j];
                p[pi].x = w[i].x;
                p[pi].y = w[i].y[j];
                p[pi].i = i;
                check();
                pi++;
            }
        }
        p[pi].x = 10;
        p[pi].y = 5;
		p[pi].i = n;
        check();
        while (!pq.empty()) pq.pop();
        for (int i = 0; i<pi+3; i++) dist[i] = INF;
        dist[0] = 0;
        pq.push(make_pair(0, 0));
        while (!pq.empty()) {
            tmp = pq.top();
            here = tmp.second;
            if (here == pi) break;
            pq.pop();
            for (int i = 0; i<=pi; i++) {
                if (i!=here && d[here][i]!=INF && dist[here]+d[here][i] < dist[i]){
                    dist[i] = dist[here]+d[here][i];
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
        cout << dist[pi] << endl;
    }
    return 0;
}

