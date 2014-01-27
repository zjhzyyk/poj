#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;

struct Node {
	int l, r, lmin, rmin, mmin;
	int lmax, rmax, mmax, sum;
}s[MAXN<<2];

int seq[MAXN];

void push_up(int p) {
	s[p].sum = s[p<<1].sum + s[p<<1|1].sum;
	s[p].lmax = max(s[p<<1].lmax, s[p<<1].sum+s[p<<1|1].lmax);
	s[p].lmin = min(s[p<<1].lmin, s[p<<1].sum+s[p<<1|1].lmin);
	s[p].rmax = max(s[p<<1|1].rmax, s[p<<1|1].sum+s[p<<1].rmax);
	s[p].rmin = min(s[p<<1|1].rmin, s[p<<1|1].sum+s[p<<1].rmin); 
	s[p].mmax = max(s[p].lmax, s[p].rmax);
	s[p].mmax = max(s[p].mmax, s[p<<1].mmax);
	s[p].mmax = max(s[p].mmax, s[p<<1|1].mmax);
	s[p].mmax = max(s[p].mmax, s[p<<1].rmax+s[p<<1|1].lmax);

	s[p].mmin = min(s[p].lmin, s[p].rmin);
	s[p].mmin = min(s[p].mmin, s[p<<1].mmin);
	s[p].mmin = min(s[p].mmin, s[p<<1|1].mmin);
	s[p].mmin = min(s[p].mmin, s[p<<1].rmin+s[p<<1|1].lmin);
}

void build(int p, int l, int r) {
	s[p].l = l, s[p].r = r;
	if (l != r) {
		int mid = (l + r) >> 1;
		build(p<<1, l, mid);
		build(p<<1|1, mid+1, r);    
		push_up(p);
	} else {
		s[p].mmax = s[p].mmin = s[p].sum = seq[r];
		s[p].lmin = s[p].rmin = s[p].lmax = s[p].rmax = seq[r];
	}
}

void modify(int p, int x) {
	if (s[p].l == s[p].r) {
		s[p].mmax = s[p].mmin = s[p].sum = seq[s[p].r];
		s[p].lmin = s[p].rmin = s[p].lmax = s[p].rmax = seq[s[p].r];
	} else {
		int mid = (s[p].l + s[p].r) >> 1;
		if (x <= mid) modify(p<<1, x);
		else modify(p<<1|1, x);
		push_up(p);
	}
}

int main() {
	int N, M, x, y;
	while (scanf("%d", &N) == 1) {
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &seq[i]);    
		}
		build(1, 1, N);
		scanf("%d", &M);
		while (M--) {
			scanf("%d %d", &x, &y);
			seq[x] = y;
			modify(1, x);
			if (s[1].mmax == s[1].sum) {
				printf("%d\n", s[1].sum-s[1].mmin);    
			} else {
				printf("%d\n", max(s[1].mmax, s[1].sum-s[1].mmin));
			}
		}
	}
	return 0;    
}