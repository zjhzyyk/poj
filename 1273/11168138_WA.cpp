#include <iostream>
#include <cstring>
using namespace std;

int c[205][205], n, m, s, e, ci, pre[205], cap, mmin, tmp;
bool vis[205], flag;

bool dfs(int st){
	vis[st] = 1;
	if (st==m)
	{
		tmp = st;
		mmin = c[pre[st]][st];
		while (pre[tmp]!=0)
		{
			if (c[pre[tmp]][tmp] < mmin) mmin = c[pre[tmp]][tmp];
			tmp = pre[tmp];
		}
		tmp = st;
		while (pre[tmp]!=0)
		{
			c[pre[tmp]][tmp] -= mmin;
			c[tmp][pre[tmp]] += mmin;
			tmp = pre[tmp];
		}
		cap+=mmin;
		//while (pre[tmp]!=0)
		//{
		//	cout << pre[tmp]<<" ";
		//}
		//cout << endl << cap << endl;
		flag = true;
		vis[st] = 0;
		return true;
	}
	for (int i = 1; i<=m; i++)
	{
		if (!vis[i] && c[st][i]!=0)
		{
			pre[i] = st;
			if (dfs(i)) break;
		}
	}
	vis[st] = 0;
	if (flag) return true;
	return false;
}

int main() {
	cin>>n>>m;
	memset(c, 0, sizeof(c));
	memset(vis, 0, sizeof(vis));
	memset(pre, 0, sizeof(pre));
	cap = 0;
	flag = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> s >> e >> ci;
		c[s][e] = ci;
	}
	while (dfs(1)) flag = false;
	cout << cap <<endl;
	//system("PAUSE");
	return 0;
}
