#include <cstdio>
#include <queue>
using namespace std;

struct node{
	int x, c;
}nd[105];

class cmp{
public:
	bool operator() (const int& aa, const int& bb) const {
		return nd[aa].c > nd[bb].c;
	}
};

int main() {
	int n, a, b, k,d[200][200], to, tmp, ni = 0, ans = 10000;
	bool vis[102];
	priority_queue<int, vector<int>, cmp> pq;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i<=n; i++)
		for (int j = 0; j<=n; j++) d[i][j] = -1;
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
	nd[0].x = a;
	nd[0].c = 0;
	pq.push(0);
	vis[a] = 1;
	ni++;
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();
		if (nd[tmp].x==b && nd[tmp].c<ans) ans = nd[tmp].c;
		for (int  i = 1; i<=n; i++){
			if (!vis[i] && d[nd[tmp].x][i]!=-1) {
				vis[i] = 1;
				nd[ni].x = i;
				nd[ni].c = nd[tmp].c + d[nd[tmp].x][i];
				pq.push(ni++);
			}
		}
	}
	if (ans==10000)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}
