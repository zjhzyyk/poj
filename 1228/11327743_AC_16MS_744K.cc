#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979323846;
const double eps = 1e-8;
const int inf = 0x7fffffff;

double minAngle;

int dblcmp(double a, double b) {
	if (fabs(a-b)<eps) return 0;
	else return a<b? -1 : 1;
}

struct P {
	int x, y;
	double angle;
	P(){}
	P(int a, int b) {x=a; y=b;}
	P operator- (const P& a){
		return P(this->x-a.x, this->y-a.y);
	}
	double dot (const P& a) {
		return this->x*a.x+this->y*a.y;
	}
	double len() {
		return sqrt((*this).dot(*this));
	}
	double cross (const P& a) {
		return this->x*a.y-this->y*a.x;
	}
	bool operator<(const P& a) const {
		return this->y==a.y ? this->x<a.x : this->y < a.y;
	}

}p[1005];

ostream &operator<<(ostream &os, const P &p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

bool cmp(const P& a, const P& b) {
	if (dblcmp(a.angle, b.angle)==0) {
		if (dblcmp(a.angle, minAngle)==0) return a.x<b.x;
		else return a.y>b.y;
	}
	else return a.angle < b.angle;
}

bool colinear(int a, int b, int pivot){
	return fabs((p[a]-p[pivot]).cross(p[b]-p[pivot])) < eps;
}

int main(){
	int t,n,a,b,start,cur;
	cin >> t;
	p[0] = P(inf, inf);
	start = 0;
	P v;
	bool flag;
//	double pa;
	int pivot,tmp;
	while (t--) {
		cin >> n;
		if (n<6) {
			for (int i = 0; i<n; i++) cin >> a >> b;
			cout << "NO" << endl;
			continue;
		}
		flag = true;
		minAngle = 1000;
		for (int i = 1; i<=n; i++) {
			cin >> a >> b;
			p[i] = P(a,b);
			if (p[i]<p[start]) start = i;
		}
		p[start].angle = -1;
		for (int i = 1; i<=n; i++) {
			if (i==start) continue;
			v = p[i]-p[start];
			p[i].angle = acos(v.dot(P(1,0))/v.len());
			if (minAngle && p[i].angle<minAngle) minAngle = p[i].angle;
		}
		sort(p+1, p+n+1, cmp);
//		for (int i=1; i<=n; i++) cout << p[i] << endl;
		cur = 3;
		if (dblcmp(p[n].angle, minAngle)==0) {
			cout << "NO" << endl;
			continue;
		}
		while (cur < n) {
			if (!colinear(cur, cur-1, cur-2)) {
//			if (dblcmp(p[cur].angle, p[cur-1].angle)!=0) {
				flag = false;
				break;
			}
//			pa = p[cur].angle;
//			pa = cur;
			pivot = cur-2;
			tmp = cur;
			while (colinear(tmp, cur+1, pivot)) {
//			while (dblcmp(pa, p[cur+1].angle)==0) {
				cur++;
			}
			cur+=2;
		}
		if (flag && dblcmp(p[n].angle, p[n-1].angle)!=0) flag = false;
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
