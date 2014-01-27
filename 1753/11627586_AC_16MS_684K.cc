#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int col[2][4], cur = 0, map[4][4], op[4][4], mmin;

void dfs(int a, int v){
	op[a][0] = v;
	if (a==3){
		int count;
		for (int i=0; i<4; i++) {
			col[cur][i] = map[i][0]^op[i][0];
			if (i-1>=0) col[cur][i] = col[cur][i]^op[i-1][0];
			if (i+1<=3) col[cur][i] = col[cur][i]^op[i+1][0];
		}
		for (int i=1; i<4; i++) {
			cur = !cur;
			for (int j = 0; j<4; j++)
				op[j][i] = !col[!cur][j];
			for (int j = 0; j<4; j++) {
				col[cur][j] = map[j][i]^op[j][i];
				if (j-1>=0) col[cur][j] = col[cur][j]^op[j-1][i];
				if (j+1<=3) col[cur][j] = col[cur][j]^op[j+1][i];
				col[cur][j] = col[cur][j]^op[j][i-1];
			}
		}
		count=0;
		for (int i = 0; i<4; i++) if (col[cur][i]==1) count++;
		if (count==4) {
			count = 0;
			for (int i = 0; i<4; i++) for (int j = 0; j<4; j++) if (op[i][j]==1) count++;
			if (count < mmin){
				mmin = count;
			}
		}
		for (int i=0; i<4; i++) {
			col[cur][i] = map[i][0]^op[i][0];
			if (i-1>=0) col[cur][i] = col[cur][i]^op[i-1][0];
			if (i+1<=3) col[cur][i] = col[cur][i]^op[i+1][0];
		}
		for (int i=1; i<4; i++) {
			cur = !cur;
			for (int j = 0; j<4; j++)
				op[j][i] = col[!cur][j];
			for (int j = 0; j<4; j++) {
				col[cur][j] = map[j][i]^op[j][i];
				if (j-1>=0) col[cur][j] = col[cur][j]^op[j-1][i];
				if (j+1<=3) col[cur][j] = col[cur][j]^op[j+1][i];
				col[cur][j] = col[cur][j]^op[j][i-1];
			}
		}
		count=0;
		for (int i = 0; i<4; i++) if (col[cur][i]==0) count++;
		if (count==4) {
			count = 0;
			for (int i = 0; i<4; i++) for (int j = 0; j<4; j++) if (op[i][j]==1) count++;
			if (count < mmin) {
				mmin = count;
			}
		}
	}
	else {
		dfs(a+1, 0);
		dfs(a+1, 1);
	}
}

int main(){
	char in[5];
	int count = 0;
	mmin = 100;
	for (int i = 0; i<4; i++) {
		scanf("%s", in);
		for (int j = 0; j<4; j++) {
			if (in[j]=='b') {
				map[i][j] = 0;
				count++;
			}
			else {
				map[i][j] = 1;
				count--;
			}
		}
	}
	if (count==16 || count==-16) {
		printf("0");
		return 0;
	}
	dfs(0,0);
	dfs(0,1);
	if (mmin==100) printf("Impossible");
	else printf("%d", mmin);
	return 0;
}
