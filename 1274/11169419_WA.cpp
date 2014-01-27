#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
int n,m, c[405][405], si, stall, pre[405], Q[405], tmp, mmin;
LL maxflow;

LL dinic(int st, int ed){
	for (int i = 0; i<=1+m+n; i++) pre[i]=-1;
	int head=0, tail=0;
	Q[tail++] = st;
	while (head < tail)
	{
		tmp = Q[head++];
		for (int i = 1; i<=1+m+n; i++)
		{
			if (i!=st && pre[i]==-1 && c[tmp][i]!=0)
			{
				pre[i] = tmp;
				Q[tail++] = i;
			}
		}
	}
	if (pre[ed]==-1) return 0;
	LL ret = 0;
	for (int i = 1; i<=1+m+n; i++)
	{
		if (c[i][ed]!=0)
		{
			mmin = c[i][ed];
			for (tmp = i; pre[tmp]!=-1; tmp = pre[tmp])
			{
				if (c[pre[tmp]][tmp] < mmin) mmin = c[pre[tmp]][tmp];
				if (mmin==0) break;
			}
			if (mmin ==0 ) continue;
			for (tmp = i; pre[tmp]!=-1; tmp = pre[tmp])
			{
				c[pre[tmp]][tmp]-=mmin;
				c[tmp][pre[tmp]]+=mmin;
			}
			c[i][ed]-=mmin;
			c[ed][i]+=mmin;
			ret+=mmin;
		}
	}
	return ret;
}

int main(){
	while (cin >> n >> m && n!=-1){
		memset(c, 0, sizeof(c));
		maxflow = 0;
		for(int i = 1; i<=n; i++) {
			c[0][i] = 1;
			cin>>si;
			while (si--) {
				cin >> stall;
				c[i][stall+n]=1;
			}
		}
		for (int i = 1+n; i<=n+m; i++) c[i][n+m+1] = 1;
		while (1) {
			LL flow = dinic(0,1+n+m);
			if (flow==0) break;
			maxflow+=flow;
		}
		cout << maxflow <<endl;
	}
	return 0;
}