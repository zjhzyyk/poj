#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

int c[205][205], n, m, s, e, ci, pre[205], mmin, tmp, Q[205];
LL maxflow;
LL dinic(int st, int ed){
	memset(pre, 0, sizeof(pre));
	int head=0, tail=0;
	Q[tail++] = st;
	while (head < tail)
	{
		tmp = Q[head++];
		for (int i = 1; i<=m; i++)
		{
			if (i!=st && pre[i]==0 && c[tmp][i]!=0)
			{
				pre[i] = tmp;
				Q[tail++] = i;
			}
		}
	}
	if (pre[ed]==0) return 0;
	LL ret = 0;
	for (int i = 1; i<=m; i++)
	{
		if (c[i][ed]!=0)
		{
			mmin = c[i][ed];
			for (tmp = i; pre[tmp]!=0; tmp = pre[tmp])
			{
				if (c[pre[tmp]][tmp] < mmin) mmin = c[pre[tmp]][tmp];
				if (mmin==0) break;
			}
			if (mmin ==0 ) continue;
			for (tmp = i; pre[tmp]!=0; tmp = pre[tmp])
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

int main() {
	while (cin>>n>>m && n!=-1) {
		memset(c, 0, sizeof(c));
		maxflow = 0;
		for (int i = 0; i<n; i++)
		{
			cin >> s >> e >> ci;
			c[s][e] += ci;
		}
		while (1) {
			LL flow = dinic(1,m);
			if (flow==0) break;
			maxflow+=flow;
		}
		cout << maxflow <<endl;
	}
	//system("PAUSE");
	return 0;
}
