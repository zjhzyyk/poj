#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int s[100005], n, m, le[100005], ei, start[100005], ed[100005],dfn, status[100005];

struct edge{
	int t, n;
}e[200010];

void addEdge(int a,int b){
	e[ei].t = a;
	e[ei].n = le[b];
	le[b] = ei++;
}

int lowbit(int t) {
	return t & (-t);
}

int getSum(int ex){
	int sum=0;
	while(ex>0)
	{
		sum+=s[ex];
		ex-=lowbit(ex);
	}
	return sum;
}

void add(int ax, int num) {
	ax = start[ax];
	while (ax <=n)
	{
		s[ax]+=num;
		ax+=lowbit(ax);
	}
}

void dfs(int x, int fa){
	dfn++;
	start[x] = dfn;
	for(int i = le[x]; i!=0; i=e[i].n){
		if (e[i].t!=fa) 
			dfs(e[i].t, x);
	}
	ed[x] = dfn;
}

void initsum() {
	for (int i = 1; i<=n; i++) s[i] = lowbit(i);
}

int main() {
	cin >> n;
	int u, v, inx;
	char op;
	ei = 1;
	dfn = 0;
	memset(le, 0, sizeof(le));
	for (int i = 1; i<n; i++) {
		cin >> u >> v;
		addEdge(u, v);
		addEdge(v,u);
	}
	dfs(1, 0);
	initsum();
	for (int i = 1; i<=n; i++) status[i] = 1;
	cin >> m;
	while (m--)
	{
		cin >> op >> inx;
		if (op=='Q') cout << (getSum(ed[inx])-getSum(start[inx]-1))<<endl;
		else {
			if (status[inx]==1) {
				status[inx]=0;
				add(inx, -1);
			}
			else {
				status[inx]=1;
				add(inx, 1);
			}
		}
	}
	//system("PAUSE");
	return 0;
}