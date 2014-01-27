#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXV 1005
#define MAXE 10005
#define INF 100000000
using namespace std;

struct edge {
	int to, next, cap, cost;
	edge(int t, int n, int c, int ct) : to(t), next(n), cap(c), cost(ct) {}
	edge() {}
}e[MAXE];

int le[MAXV], ei=0,n,m, pre[MAXV], dist[MAXV], pre_edge[MAXV], vis[MAXV];

void Add1(int u,int v,int tcap,int tcost)
{
	e[ei] = edge(v, le[u], tcap, tcost);
	le[u] = ei++;
	e[ei] = edge(u, le[v], 0, -tcost);
	le[v] = ei++;
}
void Add2(int u,int v,int tcap,int tcost)
{
	Add1(u,v,tcap,tcost);
	Add1(v,u,tcap,tcost);
}

bool spfa(int s, int t){
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i<n+2; i++) dist[i] = INF;
	int cur;
	dist[s] = 0;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		cur=Q.front();
		Q.pop(); 
		vis[cur] = 0;
		for(int i=le[cur];i!=-1;i=e[i].next)
		{
			if(dist[cur]+e[i].cost<dist[e[i].to] && e[i].cap>0)
			{
				pre[e[i].to]=cur;
				pre_edge[e[i].to]=i;
				dist[e[i].to]=dist[cur]+e[i].cost;
				if (!vis[e[i].to]) {
					Q.push(e[i].to);
					vis[e[i].to] = 1;
				}
			}
		}
	}
	return pre[t]!=-1;
}

int mcmf(int s, int t){
	int flow = INF;
	int maxflow = 0;
	int cost = 0;
	while (spfa(s, t)) {
		int cur = t;
		while (cur !=s) {
			flow = min(flow, e[pre_edge[cur]].cap);
			cur = pre[cur];
		}
		maxflow+=flow;
		cur = t;
		while (cur!=s) {
			e[pre_edge[cur]].cap-=flow;
			e[pre_edge[cur]^1].cap+=flow;
			cur=pre[cur];
		}
		cost+=flow*dist[t];
	}
	return cost;
}

int main(){
	cin >> n >> m;
	int a,b,c;
	memset(le, -1, sizeof(le));
	for (int i = 0; i<m ; i++) {
		cin >> a >> b >> c;
		Add2(a, b, 1, c);
	}
	Add1(0,1,2,0);
	Add1(n, n+1, 2, 0);
	cout << mcmf(0, n+1) << endl;
	//system("PAUSE");
	return 0;
}