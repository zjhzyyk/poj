#include <cstdio>
#include <cstring>
using namespace std;
#define MN 10005
#define INF 1000000
int n, pn, d[102][102], to, l, max, min,cnt, ans;
int main() {
	while(scanf("%d", &n) && n!=0) {
		for (int i = 0; i<=n; i++) {
			for (int j = 0; j<=n; j++) {
				d[i][j] = INF;
			}
		}
		max = 0;cnt=0;min=INF;ans=-1;
		for (int i = 0; i<n; i++) {
			scanf("%d", &pn);
			d[i+1][i+1] = 0;
			while(pn--) {
				scanf("%d %d", &to, &l);
				d[i+1][to] = l;
			}
		}
		for (int k = 1; k<=n; k++) {
			for (int i = 1; i<=n; i++) {
				for (int j = 1; j<=n; j++) {
					if (d[i][k]!=INF && d[k][j]!=INF && (d[i][k] + d[k][j])<d[i][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		for (int i = 1; i<=n; i++) {
			cnt = 0;max=0;
			for (int j = 1; j<=n; j++) {
				if (i==j) continue;
				if (d[i][j]!=0){
					cnt++;
					if (d[i][j]>max) max = d[i][j];
				}
			}
			if (cnt==(n-1) && max<min){
				min=max;
				ans = i;
			}
		}
		if (ans==-1)
			printf("disjoint\n");
		else
			printf("%d %d\n", ans, min);
	}
	return 0;
}
