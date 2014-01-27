#include <cstdio>
using namespace std;

int s[1030][1030], n, first, x,y,a,l,r,b,t;

int lowbit(int t) {
	return t & (-t);
}

int getSum(int ex, int ey){
	int sum=0;
	int temp=ey;
	while(ex>0)
	{
		ey=temp;//
		while (ey>0)
		{
			sum+=s[ex][ey];
			ey-=lowbit(ey);
		}

		ex-=lowbit(ex);
	}
	return sum;
}

void add(int ax, int ay, int num) {
	int temp=ay;
	while (ax <=n)
	{
		ay=temp;
		while(ay<=n)
		{
			s[ax][ay]+=num;
			ay+=lowbit(ay);
		}
		ax+=lowbit(ax);
	}
}

int main() {
	scanf("%*d %d", &n);
	for (int i = 0; i<= n; i++) for (int j = 0; j<=n; j++) s[i][j] = 0;
	scanf("%d", &first);
	while (first!=3) {
		if (first==1) {
			scanf("%d %d %d", &x, &y, &a);
			add(x+1,y+1,a);
		}
		else {
			scanf("%d %d %d %d", &l, &b, &r, &t);
			printf("%d\n", getSum(r+1, t+1)-getSum(l,t+1)-getSum(r+1,b)+getSum(l,b));
		}
		scanf("%d", &first);
	}
	return 0;
}