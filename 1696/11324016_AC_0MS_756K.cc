#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979323846;
const double eps = 1e-8;

bool vis[55];
int n;

struct P {
	int x, y;
	P(){}
	P(int a, int b) {x=a; y=b;}
	P operator- (const P& a){
		return P(this->x-a.x, this->y-a.y);
	}
	double operator* (const P& a) {
		return this->x*a.x+this->y*a.y;
	}
	double len() {
		return sqrt((*this)*(*this));
	}
	double cross (const P& a) {
		return this->x*a.y-this->y*a.x;
	}
	bool operator<(const P& a) const {
		return this->y==a.y ? this->x<a.x : this->y < a.y;
	}
}p[55];

double angles[55][55];

int dblcmp(double a, double b) {
	if (fabs(a-b)<eps) return 0;
	else return a<b? -1 : 1;
}

int find(int pre, int cur){
	double tmp, mmin;
	mmin = 100000;
	double theta = angles[pre][cur];
	int ret = 0;
	for (int i = 1; i<=n; i++) {
		if (vis[i]) continue;
		tmp = angles[cur][i]-theta;
		if (tmp < 0) tmp += 2*pi;
		if (tmp < pi && tmp < mmin) {
			ret = i;
			mmin = tmp;
		}
	}
	return ret;
}

int main(){
	int m,a,b,c,next,st[55],top, pre,cur, start,second;
	double tmp;
	P v;
	cin >> m;
	p[0] = P(1000,1000);
	while (m--) {
		cin >> n;
		start = 0;
		for (int i = 1; i<=n; i++) {
			cin >> a >> b >> c;
			p[i].x = b;
			p[i].y = c;
			if (p[i] < p[start]) start = i;
			for (int j = 1; j<i; j++) {
				v = p[i]-p[j];
				tmp = v*P(1,0)/v.len();
				tmp = acos(tmp);
				if (P(1,0).cross(v)<0) tmp = 2*pi - tmp;
				angles[j][i] = tmp;
				angles[i][j] = (dblcmp(tmp+pi,2*pi)>=0 ? tmp-pi : tmp+pi);
			}
		}
		second = 0;
		angles[start][second] = 1000;
		for (int i = 1; i<=n; i++) {
			if (i==start) continue;
			if (angles[start][i] < angles[start][second]) second = i;
		}
		int i = start;
		int j = second;
		memset(vis, 0, sizeof(vis));
		top = 0;
		st[top++] = i;
		st[top++] = j;
		vis[i] = vis[j] = 1;
		pre = i;
		cur = j;
		while (next = find(pre, cur)) {
			vis[next] = 1;
			st[top++] = next;
			pre = cur;
			cur = next;
		}
		cout << top;
		if (top) cout << " "; else cout << endl;
		for (i = 0; i<top; i++)  {
			cout << st[i];
			if (i==top-1) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}
