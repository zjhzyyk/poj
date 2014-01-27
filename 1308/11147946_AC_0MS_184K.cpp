#include <cstdio>
#include <cstring>
using namespace std;

int f, t, cn = 1, p[5000];
bool flag;

int find(int x) {
	int tmp;
	if (x == p[x]) return x;
	tmp = p[x];
	p[x] = find(tmp);
	return p[x];
}

void unionset(int x, int y) {
	if (p[x]==0) p[x] = x;
	if (p[y]==0) p[y] = y;
	int xp = find(x);
	int yp = find(y);
	if (y!=yp) {
		flag = false; // only one edge, one parent
		return;
	}
	if (xp==yp) {
		flag=false; // duplicated edge or cycle exists
		return;
	}
	p[yp] = xp;
}

int main() {
	while (scanf("%d %d", &f, &t) && f>=0 && t>=0) {
		memset(p, 0, 5000);
		flag = true;
		while (f>0&&t>0) {
			if (flag) unionset(f,t);
			scanf("%d %d", &f, &t);
		}
		if (flag)
			for (int i = 1; i<5000; i++)
				if (p[i]!=0 && p[i-1]!=0 && find(i)!=find(i-1))
					flag=false; //connect, one root
		if (flag) printf("Case %d is a tree.\n", cn++);
		else printf("Case %d is not a tree.\n", cn++);
	}
	return 0;
}
