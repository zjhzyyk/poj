#include <cstdio>
#include <cstring>
#define INF 1000000000
using namespace std;

struct edge{
	int f, t, d;
}e[20005];

int main() {
	int n, ml, md, ei = 0, dist[1005], ans;
	bool flag;
	scanf("%d %d %d", &n, &ml, &md);
	for (int i = 0; i<ml; i++) {
		scanf("%d %d %d", &e[ei].f, &e[ei].t, &e[ei].d);
		ei++;
	}
	for (int i = 0; i<md; i++) {
		scanf("%d %d %d", &e[ei].t, &e[ei].f, &e[ei].d);
		e[ei].d = -e[ei].d;
		ei++;
	}
	//bellmanford
	for (int i = 1; i<=n; i++) dist[i] = INF;
	dist[1] = 0;
	for (int i = 1; i<n; i++) {
		flag = false;
		for (int j = 0; j<ei; j++) {
			if ( (dist[e[j].f] + e[j].d) < dist[e[j].t]) {
				flag = true;
				dist[e[j].t] = dist[e[j].f] + e[j].d;
			}
		}
		if (!flag)
			break;
	}
	for (int j = 0; j<ei; j++) {
		if ( (dist[e[j].f] + e[j].d) < dist[e[j].t]){
			printf("-1");
			return 0;
		}
	}
	ans = dist[n]-dist[1];
	if (ans>=INF) printf("-2");
	else printf("%d", ans);
	return 0;
}
