#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <iostream>
#include <cmath>
using namespace std;
const int INF = 2000000000;
typedef pair<int,int> PII;

int main() {
	int n, p[202][2], d[202][202], dist[202], here, cn = 1;
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	while (cin >> n && n!=0) {
		for (int i = 0; i<n; i++) {
			cin >> p[i][0] >> p[i][1];
			for (int j = 0; j<i; j++)
				d[j][i] = d[i][j] = (p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
		}
		for (int i = 0; i<n+2; i++) dist[i] = INF;
		while (!pq.empty()) pq.pop();
		pq.push(make_pair(0, 0));
		dist[0] = 0;
		while (!pq.empty()) {
			PII tmp = pq.top();
			here = tmp.second;
			if (here == 1) break;
			pq.pop();
			for (int i = 0; i<n; i++) {
				if (i!=here && d[here][i]!=INF && max(dist[here], d[here][i])<dist[i]) {
					dist[i] = max(dist[here], d[here][i]);
					pq.push(make_pair(dist[i], i));
				}
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", cn++, sqrt((double)dist[1]));
		scanf("%*c");
	}
	//system("PAUSE");
	return 0;
}