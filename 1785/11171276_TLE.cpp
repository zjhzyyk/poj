#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
struct node{
	char self[10];
	int left, right, p;
}nd[50010];

inline bool cmp(const node& a, const node& b){
	return a.p > b.p;
}

void output(int x){
	if (x==-1) return;
	printf("(");
	output(nd[x].left);
	printf("%s/%d", nd[x].self, nd[x].p);
	output(nd[x].right);
	printf(")");
}

int main() {
	int n, cur, lin, j;
	char in[4];
	while (cin >> n && n!=0) {
		for (int i = 0; i<n; i++) {
			cin >> in;
			lin = strlen(in);
			memset(nd[i].self, 0, sizeof(nd[i].self));
			for (j = 0; j<lin; j++) {
				if (in[j]!='/') 
					nd[i].self[j] = in[j];
				else break;
			}
			nd[i].p = 0;
			j++;
			for (;j<lin; j++) {
				nd[i].p*=10;
				nd[i].p+=(in[j]-'0');
			}
			nd[i].left = -1;
			nd[i].right = -1;
		}
		sort(nd, nd+n, cmp);
		for (int i = 1; i<n; i++) {
			cur = 0;
			while (1) {
				if (strcmp(nd[i].self, nd[cur].self)>0)
					if (nd[cur].right!=-1) {
						cur = nd[cur].right;
					}
					else {
						nd[cur].right = i;
						break;
					}
				else
					if (nd[cur].left!=-1) {
						cur = nd[cur].left;
					}
					else {
						nd[cur].left = i;
						break;
					}
			}
		}
		output(0);
		printf("\n");
	}
	return 0;
}