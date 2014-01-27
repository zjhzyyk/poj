#include <cstdio>
#include <cstring>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

struct edgelist{
	int to, next, same;
}e[20005];

struct bridge {
	int a, b;
}b[10002];
bool mp[5005][5005];
int le[5005], n, m, f, t, low[5005], dfn[5005], id, d[5005], cnt, ln, maxd, visited[5005];

void dfs(int x, int fa){
	dfn[x] = low[x] = id;
	visited[x] = 1;
	if (id>maxd) maxd = id;
	id++;
	for (int i = le[x]; i!=-1; i = e[i].next) {
		if (e[i].same==fa) continue;
		int to = e[i].to;
		if (dfn[to]!=0 && visited[x]==1) {
			if (dfn[to] < low[x]) low[x] = dfn[to];
		}
		else {
			dfs(to, i);
			if (low[to]<low[x]) low[x] = low[to];
			if (low[x] < low[to]) {
				b[cnt].a = x;
				b[cnt].b = to;
				cnt++;
			}
		}
	}
	visited[x] = 2;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n+1; i++) le[i] = -1;
	id = 1; cnt = 0; ln = 0;
	maxd = 0;
	memset(d, 0, sizeof(d));
	for (int i = 0; i<2*m; i++) {
		scanf("%d %d", &f, &t);
		if(mp[f][t]) {
			i++;
			continue;
		}
		mp[f][t] = mp[t][f] = 1;
		e[i].to = f;
		e[i].next = le[t];
		e[i].same = i+1;
		le[t] = i;
		i++;
		e[i].to = t;
		e[i].next = le[f];
		e[i].same = i-1;
		le[f] = i;
	}
	dfs(1, -1);
	for (int i = 0; i<cnt; i++) {
		d[low[b[i].a]]++;
		d[low[b[i].b]]++;
	}
	maxd++;
	for (int i = 0; i<maxd; i++) if (d[i]==1) ln++;
	printf("%d", (ln+1)/2);
	return 0;
}
