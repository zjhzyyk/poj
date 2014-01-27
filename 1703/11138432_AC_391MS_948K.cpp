#include <cstdio>
using namespace std;

int p[100002], x[100002], n, m, aa, bb;
char c[1];

void make_set(int a){
	for (int i = 0; i<a; i++) {
		p[i] = i;
		x[i] = 0;
	}
}

int find_set(int a){
	int tmp;
	if (a==p[a]) return a;
	tmp = p[a];
	p[a] = find_set(tmp);
	//update
	x[a] = x[tmp] ^ x[a];
	return p[a];
}

void union_set(int a, int b){
	int xa = find_set(a);
	int xb = find_set(b);
	if (xa==xb) return;
	p[xa] = xb;
	if (x[a]==x[b]) x[xa] = x[xa]^1;
}

int main() {
	int cn;
	scanf("%d", &cn);
	while (cn--) {
		scanf("%d%d", &n, &m);
		make_set(n);
		while (m--) {
			scanf("%s %d %d", c, &aa, &bb);
			if (c[0]=='A') {
				if (find_set(aa)==find_set(bb)) {
					if (x[aa]==x[bb]) printf("In the same gang.\n");
					else printf("In different gangs.\n");
				}
				else {
					printf("Not sure yet.\n");
				}
			}
			else {
				union_set(aa,bb);
			}
		}
	}
	return 0;
}
