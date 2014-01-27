#include <cstdio>
#include <cstring>
using namespace std;

struct edge{
	int a,d,next;
}e[80004];

int le[40002], n, m, f1, f2, l, ei = 1, ma, second[40002], first[40002];

void dfs(int x, int fa) {
	first[x] = 0;
	second[x] = 0;
	for (int i = le[x]; i!=0; i=e[i].next) {
		if (e[i].a!=fa) {
			dfs(e[i].a, x);
			if ((first[e[i].a]+e[i].d)>first[x]) {
				second[x] = first[x];
				first[x] = first[e[i].a]+e[i].d;
			}
			else if ((first[e[i].a]+e[i].d)>second[x])
				second[x] = first[e[i].a]+e[i].d;
		}
	}
	if ((first[x]+second[x])>ma) ma = first[x]+second[x];
}

int main() {
	ma = 0;
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
	dfs(1, 0);
	printf("%d", ma);
	return 0;
}
