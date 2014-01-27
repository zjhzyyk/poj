#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
const int INF = 2000000000;
typedef pair<int,int> PII;

int main() {
	int n, a, b, k,d[105][105], to;
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=n; j++) d[i][j] = INF;
	}
	for (int i = 0; i<n; i++) {
		scanf("%d", &k);
		if (k==0) continue;
		scanf("%d", &to);
		d[i+1][to] = 0;
		k--;
		while(k--){
			scanf("%d", &to);
			d[i+1][to] = 1;
		}
	}
	vector<int> dist(n+2, INF);
	pq.push(make_pair (0, a));
	dist[a] = 0;
	while (!pq.empty()) {
		PII tmp = pq.top();
		if (tmp.second == b) break;
		pq.pop();
		int here = tmp.second;
		for (int  i = 1; i<=n; i++){
			if (i!=here && d[here][i]!=INF && dist[here]+d[here][i] < dist[i]) {
				dist[i] = dist[here]+d[here][i];
				pq.push(make_pair(dist[i], i));
			}
		}
	}
	if (dist[b]==INF)
		printf("-1\n");
	else
		printf("%d\n", dist[b]);
	//system("PAUSE");
	return 0;
}