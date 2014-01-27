#include <stdio.h>
#include <cstdlib>
int main() {
	int n, m, farm[40010][4], f1, f2, l, qn, a,b,id;
	char d;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<=n; i++) farm[i][3] = -1;
	scanf("%d %d %d %c", &f1, &f2, &l, &d);
	farm[f1][0] = 0;
	farm[f1][1] = 0;
	farm[f1][2] = 1;
	farm[f2][2] = 1;
	farm[f2][0] = 0;
	farm[f2][1] = 0;
	if (d=='N') farm[f2][1] += l;
	if (d=='S') farm[f2][1] -= l;
	if (d=='E') farm[f2][0] += l;
	if (d=='W') farm[f2][0] -= l;
	farm[f1][3] = 1;
	farm[f2][3] = 1;
	for (int i = 1; i<m; i++){
		scanf("%d %d %d %c", &f1, &f2, &l, &d);
		if (farm[f1][3]==-1) {
			farm[f1][0] = farm[f2][0];
			farm[f1][1] = farm[f2][1];
			if (d=='N') farm[f1][1] =farm[f2][1] - l;
			if (d=='S') farm[f1][1] =farm[f2][1] + l;
			if (d=='E') farm[f1][0] =farm[f2][0] - l;
			if (d=='W') farm[f1][0] =farm[f2][0] + l;
			farm[f1][3]=1;
			farm[f1][2]=i+1;
		}
		else {
			farm[f2][0] = farm[f1][0];
			farm[f2][1] = farm[f1][1];
			if (d=='N') farm[f2][1] =farm[f1][1] + l;
			if (d=='S') farm[f2][1] =farm[f1][1] - l;
			if (d=='E') farm[f2][0] =farm[f1][0] + l;
			if (d=='W') farm[f2][0] =farm[f1][0] - l;
			farm[f2][3]=1;
			farm[f2][2]=i+1;
		}
	}
	scanf("%d", &qn);
	while (qn--) {
		scanf("%d %d %d", &a,&b,&id);
		if (farm[a][2]>id || farm[b][2]>id) {
			printf("-1\n");
		}
		else {
			printf("%d\n", abs(farm[a][0]-farm[b][0])+abs(farm[a][1]-farm[b][1]));
		}
	}
	return 0;
}
