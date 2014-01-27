#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n, m, k, id=0, p[40005], x[40005], y[40005], e[40005][4], ans[10005];
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

struct query{
	int a,b,i,at;
}q[10005];

void make_set(){
	for (int i = 0; i< n; i++) {
		p[i] = i;
		x[i] = y[i] = 0;
	}
}
int find_set(int a) {
	int tmp;
	if (a==p[a]) return a;
	tmp = p[a];
	//find parent
	p[a] = find_set(tmp);
	//update
	x[a] += x[tmp];
	y[a] += y[tmp];
	return p[a];
}
void union_set(int a, int b, int xd, int yd) {
	int ra = find_set(a);
	int rb = find_set(b);
	if (ra==rb) return;
	p[rb] = ra;
	x[rb] += x[a]+xd-x[b];
	y[rb] += y[a]+yd-y[b];
}

inline bool cmp (const query& a, const query& b) {
	return a.i < b.i;
}

int main() {
	scanf("%d%d", &n, &m);
	make_set();
	char c;
	for (int i= 0; i<m; i++){
		scanf("%d%d%d %c", &e[i][0], &e[i][1], &e[i][2], &c);
		switch (c) {
		case 'N' : e[i][3] = 0; break;
		case 'S' : e[i][3] = 1; break;
		case 'E' : e[i][3] = 2; break;
		case 'W' : e[i][3] = 3; break;
		}
	}
	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].i);
		q[i].at = i;
	}
	sort(q, q+k, cmp);
	for (int i = 0; i<m; i++) {
		//operate
		union_set(e[i][0], e[i][1], dx[e[i][3]]*e[i][2], dy[e[i][3]]*e[i][2]);
		while (q[id].i==(i+1)) {
			//print result
			if (find_set(q[id].a)==find_set(q[id].b))
				ans[q[id].at] = abs(x[q[id].a]-x[q[id].b])+abs(y[q[id].a]-y[q[id].b]);
			else
				ans[q[id].at] = -1;
			id++;
		}
	}
	for (int i = 0; i<k; i++) printf("%d\n", ans[i]);
	return 0;
}
