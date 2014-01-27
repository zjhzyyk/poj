#include <cstdio>
using namespace std;

int map[52][52],g[52][52], t[16][4] = {{1,1,1,1},//N S W E
		{1,1,0,1},//1
		{0,1,1,1},//2
		{0,1,0,1},//3
		{1,1,1,0},//4
		{1,1,0,0},//5
		{0,1,1,0},//6
		{0,1,0,0},//7
		{1,0,1,1},//8
		{1,0,0,1},//9
		{0,0,1,1},//10
		{0,0,0,1},//11
		{1,0,1,0},//12
		{1,0,0,0},//13
		{0,0,1,0},//14
		{0,0,0,0}//15
}, mmax = 1, num = 0, h,w, count;

void dfs(int a, int b){
	count++;
	g[a][b] = num+1;
	if (t[map[a][b]][0]==1 && (a-1)>=0 && g[a-1][b]==0) dfs(a-1, b);
	if (t[map[a][b]][1]==1 && (a+1)<h && g[a+1][b]==0) dfs(a+1, b);
	if (t[map[a][b]][2]==1 && (b-1)>=0 && g[a][b-1]==0) dfs(a, b-1);
	if (t[map[a][b]][3]==1 && (b+1)<w && g[a][b+1]==0) dfs(a, b+1);
}

int main() {
	scanf("%d%d", &h, &w);
	for (int i = 0; i<h; i++) for (int j = 0; j<w; j++) {
		scanf("%d", &map[i][j]);
		g[i][j] = 0;
	}
	for (int i = 0; i<h; i++) for (int j = 0; j<w; j++) {
		if (g[i][j]==0) {
			count = 0;
			num++;
			dfs(i,j);
			if (count>mmax) mmax = count;
		}
	}
	printf("%d\n%d", num, mmax);
	return 0;
}
