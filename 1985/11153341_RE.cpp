#include <cstdio>
#include <cstring>
using namespace std;

struct edge{
	int a,d,next;
}e[40002];

int le[40002], n, m, f1, f2, l, ei = 1, max[40002];

void dfs(int x, int fa, int up) {
	max[x] = up;
	for (int i = le[x]; i!=0; i=e[i].next) {
		if (e[i].a!=fa) {
			dfs(e[i].a, x, e[i].d);
			if ((up+max[e[i].a])>max[x]) max[x] = up+max[e[i].a];
		}
	}
}

int main() {
	int ma = 0;
	memset(le, 0, sizeof(le));
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m ; i++) {
		scanf("%d %d %d %*c", &f1, &f2, &l);
		e[ei].a = f1;
		e[ei].next = le[f2];
		e[ei].d = l;
		le[f2] = ei++;
		e[ei].a = f2;
		e[ei].next = le[f1];
		e[ei].d = l;
		le[f1] = ei++;
	}
	dfs(1, 0, 0);
	for (int i = le[1]; i!=0; i=e[i].next) {
		ma+=max[e[i].a];
	}
	printf("%d", ma);
	return 0;
}
