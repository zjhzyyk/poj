#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct vertex {
	double x;
	int next;
}v[2005];

int vi[2005];
int stack[2005], head = 0;

bool cmp(int a, int b) {
	return fabs(v[a].x-v[b].x)<1e-8 ? v[b].next<0 : v[a].x < v[b].x;
}

int main(){
	int cn = 1, ans;
	int n,vx;
	double x,y, d;
	double tmp;
	while (cin >> n >> d && (n!=0 || fabs(d)>1e-8)) {
		bool flag = true;
		vx = 0;
		ans = 0;
		for (int i = 0; i<n; i++) {
			cin >> x >> y;
			if (flag==false) continue;
			if (y>d) {
				flag = false;
				continue;
			}
			tmp = sqrt(d*d-y*y);
			v[vx].x = x - tmp;
			v[vx].next = vx+1;
			vx++;
			v[vx].x = x + tmp;
			v[vx].next = -1;
			vx++;
		}
		if (flag==false) {
			cout << "Case " << (cn++) << ": -1" << endl;
			continue;
		}
		for (int i = 0; i<vx; i++) vi[i] = i;
		sort(vi, vi+vx, cmp);

		for (int i = 0; i<vx; i++) {
			if (v[vi[i]].next==-2) continue;
			if (v[vi[i]].next!=-1) stack[head++] =v[vi[i]].next;
			else {
				ans++;
				while (head) v[stack[--head]].next = -2;
			}
		}
		cout << "Case " << (cn++) << ": " << ans << endl;
	}
	return 0;
}
