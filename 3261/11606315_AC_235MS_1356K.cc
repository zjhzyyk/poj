#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
const int Max = 20010;

int  num[Max];
int sa[Max], rank[Max], height[Max];
int wa[Max], wb[Max], wv[Max], wd[Max];

int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

bool cmp1(int a, int b) {
	return num[a]==num[b] ? a<b : num[a]<num[b];
}

void da(int *r, int n){
    int i, j, p, *x = wa, *y = wb, *t, m;
    for (i=0; i<n; i++) sa[i] = i;
    sort(sa,sa+n,cmp1);
    for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
		x[sa[i]] = r[sa[i-1]]==r[sa[i]] ? p - 1: p ++;
    for(j = 1, p = 1, m=n; p < n; j *= 2, m = p){
    	for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
		for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
		for(i = 0; i < n; i ++) wv[i] = x[y[i]];
		for(i = 0; i < m; i ++) wd[i] = 0;
		for(i = 0; i < n; i ++) wd[wv[i]] ++;
		for(i = 1; i < m; i ++) wd[i] += wd[i-1];
		for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
		for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
    }
}

void calHeight(int *r, int n){
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i++]] = k)
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
}

int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i<n; i++) cin >> num[i];
	num[n] = -1;
    da(num, n + 1);
	calHeight(num, n);
	int begin = 0, end = n, mid, count, ans=0;
	k--;
	while (end>=begin) {
		count = 0;
		mid = (begin+end)/2;
		for (int i=2; i<=n; i++) {
			if (height[i]>=mid) count++;
			else count = 0;
			if (count==k) break;
		}
		if (count==k) {
			begin = mid+1;
			ans = mid;
		}
		else end = mid-1;
	}
	cout << ans;
    return 0;
}
