#include <stdio.h>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
#define clr(x)memset(x,0,sizeof(x))
#define maxn 10005
int g[maxn][maxn], cnt[maxn], ans;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	clr(g);
	clr(cnt);
	int a,b;
	ans = 0;
	vector<int>from[maxn];
	vector<int>to[maxn];
	while(m--)
	{
		scanf("%d%d",&a,&b);
		g[b][a]=1;
		cnt[b]++;
		from[b].push_back(a);
		to[a].push_back(b);
	}
	int i,j,k;
	int u,v;
	for(k=1;k<=n;k++){
		for(i=0;i<from[k].size();i++){
			for(j=0;j<to[k].size();j++)
			{
				u=from[k][i];
				v=to[k][j];
				if(!g[v][u] && v!=u)
				{
					g[v][u]=1;
					cnt[v]++;
					from[v].push_back(u);
					to[u].push_back(v);
				}
			}
		}
	}
	for (int i = 1; i<= n; i++) if (cnt[i]==(n-1)) ans++;
	cout << ans << endl;
	return 0;
}