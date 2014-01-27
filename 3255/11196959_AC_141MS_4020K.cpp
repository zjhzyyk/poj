#include<iostream>
#include<queue>
#include <functional>
using namespace std;

#define inf 1000000000

int n,m;
int edgenum;
int st,et;

int head[5005];
int dis[5005][2];
int cnt[5005][2];
int vst[5005][2];

typedef struct edge
{
	int from,to;
	int dis;
	int next;
}Edge;
Edge edge[200005];

typedef pair<int, pair<int, int>> P;

priority_queue<P, vector<P>, greater<P> > Q;

void addedge(int a,int b,int c)
{
	edge[edgenum].from=a;edge[edgenum].to=b;edge[edgenum].dis=c;edge[edgenum].next=head[a];head[a]=edgenum++;
}

int Dijkstra()
{
	memset(vst,0,sizeof(vst));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
		dis[i][0]=dis[i][1]=inf;
	Q.push(make_pair(dis[st][0], make_pair(st, 0)));
	dis[st][0]=0;
	cnt[st][0]=1;
	while(!Q.empty())
	{
		P top=Q.top();
		Q.pop();
		int v=top.second.first;
		int flag=top.second.second;
		if(vst[v][flag])
			continue;
		vst[v][flag]=1;                                     
		for(int i=head[v];i!=-1;i=edge[i].next)            
		{
			int to=edge[i].to;
			int dist=dis[v][flag]+edge[i].dis;
			if(dist<dis[to][0])                              
			{
				if(dis[to][0]!=inf)                          
				{
					dis[to][1]=dis[to][0];                               
					cnt[to][1]=cnt[to][0];                   
					Q.push(make_pair(dis[to][1], make_pair(to, 1)));
				}                                            
				dis[to][0]=dist;                             
				cnt[to][0]=cnt[v][flag];                       
				Q.push(make_pair(dis[to][0], make_pair(to, 0)));
			}
			else if(dist==dis[to][0])                      
			{
				cnt[to][0]+=cnt[v][flag];                  
			}
			else if(dist<dis[to][1])                       
			{
				dis[to][1]=dist;                           
				cnt[to][1]=cnt[v][flag];                   
				Q.push(make_pair(dis[to][1], make_pair(to, 1)));
			}
			else if(dist==dis[to][1])                      
			{
				cnt[to][1]+=cnt[v][flag];                  
			}
		}
	}
	if (dis[n][1] == inf) return dis[n][0];
	return dis[n][1];
}

int main()
{
	edgenum=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
		addedge(b,a,c);
	}
	st = 1; et = n;
	printf("%d\n",Dijkstra());
	//system("PAUSE");
	return 0;
}