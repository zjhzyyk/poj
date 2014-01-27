#include <cstdio>
#include <cstring>
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
int n,m, d[2005][2005],ai,bi,li, tmp, mi[2005], mmin = 0;

int calc(int x){
	if (x==1) return 0;
	if (mi[x]!=0) return mi[x];
	for (int i = 1; i<2001; i++) {
		if (d[x][i]!=0) {
			if (mi[x]==0) mi[x] = calc(i) + d[x][i];
			mi[x] = min(mi[x], calc(i) + d[x][i]);
		}
	}
	return mi[x];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i< n+1; i++) for (int j = 0; j<n+1; j++) d[i][j] = 0;
	memset(mi, 0, n+2);
	while (m--) {
		scanf("%d %d %d", &ai, &bi, &li);
		d[ai][bi] = li;
		d[bi][ai] = li;
	}
	for (int i=2; i<2001; i++){
		if (mmin < calc(i)) mmin = calc(i);
	}
	printf("%d", mmin);
	return 0;
}
