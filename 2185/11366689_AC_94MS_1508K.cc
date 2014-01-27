#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char in[10005][80];
int t[10005],r,c, height;

void nextrow(){
	t[0] = -1;
	int i=0, j=-1;
	while (i<r) {
		if(j==-1 || strcmp(in[i],in[j])==0){
			i++,j++;
			t[i]=j;
		}else j=t[j];
	}
}

bool equal(int a, int b) {
	for (int i = 0; i<height; i++) {
		if (in[i][a]!=in[i][b])
			return false;
	}
	return true;
}

void nextcol(){
	t[0] = -1;
	int i=0, j=-1;
	while (i<c) {
		if(j==-1 || equal(i,j)){
			i++,j++;
			t[i]=j;
		}else j=t[j];
	}
}

int main(){
	scanf("%d%d", &r, &c);
	for (int i = 0; i<r; i++) {
		scanf("%s", in[i]);
	}
	nextrow();
	height = r-t[r];
	nextcol();
	int width = c-t[c];
	printf("%d", width*height);
	return 0;
}
