#include <iostream>
#include <cstring>
using namespace std;

bool conn[1002][1002];
bool vis[1002];
int le[1003], ei;

struct edge {
	int a, n;
}e[10005];

void dfs(int x, int an) {
	vis[x] = 1;
	conn[an][x] = conn[x][an] = 1;
	for (int i = le[x]; i!=0; i=e[i].n )
		if (!vis[e[i].a]) dfs(e[i].a, an);
}

int main() {
	memset(conn, 0, sizeof(conn));
	memset(le, 0, sizeof(le));
	int n, m, x, y ,f ,t, cnt = 0;
	ei = 1; 
	cin >> n >> m;
	for (int i = 0; i < m; i++)  {
		cin >> x >> y;
		e[ei].a = y;
		e[ei].n = le[x];
		le[x] = ei++;
	}
	for (int i = 1; i<=n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
	}
	for (int i = 1; i<n; i++) for (int j= i+1; j<=n; j++) if(!conn[i][j]) cnt++;
	cout << cnt << endl;
	//system("PAUSE");
	return 0;
}