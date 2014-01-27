#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct No {
	int mmin, mmax, lmin, rmin, lmax, rmax, sum, b, e;
}nd[400040];

int n, val[100005], m, ina, inb;

void calc ( int node) {
	nd[node].sum = nd[node*2].sum + nd[(node*2)+1].sum;
	nd[node].mmin = min(nd[node*2].rmin+nd[(node*2)+1].lmin, min(nd[node*2].mmin, nd[(node*2)+1].mmin));
	nd[node].mmax = max(nd[node*2].rmax+nd[(node*2)+1].lmax, max(nd[node*2].mmax, nd[(node*2)+1].mmax));
	nd[node].lmin = min(nd[node*2].lmin, nd[node*2].sum+nd[(node*2)+1].lmin);
	nd[node].lmax = max(nd[node*2].lmax, nd[node*2].sum+nd[(node*2)+1].lmax);
	nd[node].rmin = min(nd[(node*2)+1].rmin, nd[node*2].rmin+nd[(node*2)+1].sum);
	nd[node].rmax = max(nd[(node*2)+1].rmax, nd[node*2].rmax+nd[(node*2)+1].sum);
}

void initialize(int node, int b, int e)
{
	nd[node].b = b;
	nd[node].e= e;
	if (b == e) {
		nd[node].mmax = nd[node].mmin = nd[node].lmax = nd[node].sum = 
		nd[node].lmin = nd[node].rmax = nd[node].rmin = val[b];
	}
	else
	{
		initialize(node*2, b, (b + e)/2);
		initialize((node*2)+1, ((b + e)/2) + 1, e);
		calc(node);
	}
}

void update(int id, int v) {
	int tmp = 1;
	while (nd[tmp].b!=id || nd[tmp].e!=id) 
		tmp = id> (nd[tmp].b+nd[tmp].e)/2 ? (tmp *2+1) : (tmp*2); 
	nd[tmp].mmax = nd[tmp].mmin = nd[tmp].lmax = nd[tmp].sum = 
		nd[tmp].lmin = nd[tmp].rmax = nd[tmp].rmin = v;
	while (tmp!=0){ 
		calc(tmp>>1);
		tmp = tmp>>1;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i<=n; i++) cin >> val[i];
	cin >> m;
	cin >> ina >> inb;
	val[ina] = inb;
	initialize(1, 1, n);
	if (nd[1].mmax==nd[1].sum)
		cout << nd[1].sum - nd[1].mmin << endl;
	else cout << max(nd[1].mmax, nd[1].sum-nd[1].mmin) << endl;
	for (int i=1; i<m; i++) {
		cin >> ina>>inb;
		if (val[ina]!=inb){
			update(ina, inb);
			val[ina] = inb;
		}
		if (nd[1].mmax==nd[1].sum)
			cout << nd[1].sum - nd[1].mmin<<endl;
		else
			cout << max(nd[1].mmax, nd[1].sum-nd[1].mmin) << endl;
	}
	//system("PAUSE");
	return 0;
}