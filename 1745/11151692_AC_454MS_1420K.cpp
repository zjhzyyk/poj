#include <cstdio>
using namespace std;
int num[10001];

bool f[10001][101],flag;
int k,n;

bool dfs(int i,int sum)
{
	if(i==n)
	{
		if(sum%k==0)
		{

			flag=1;
			return 1;
		}
		else return 0;
	}
    if(!f[i][sum])
	{
		f[i][sum]=1;
		dfs(i+1,(sum+num[i+1])%k);
		dfs(i+1,(k+sum-num[i+1])%k);
	}
	return flag;
}


int main()
{
	int i,a;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		num[i]=a%k;
	}
    if(dfs(1,num[1]))
		printf("Divisible\n");
    else
	    printf("Not divisible\n");
    return 0;

}
