#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const double pi = 3.14159265358979323846;
const double eps = 1e-8;
const int inf = 0x7fffffff;

int dblcmp(double a, double b) {
	if (fabs(a-b)<eps) return 0;
	else return a<b? -1 : 1;
}

struct P {
	double x, y;
	P(){}
	P(double a, double b) {x=a; y=b;}
	P operator+ (const P& a) {
		return P(this->x+a.x, this->y+a.y);
	}
	P operator- (const P& a){
		return P(this->x-a.x, this->y-a.y);
	}
	P operator* (const double a) {
		return P(a*this->x, a*this->y);
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
		return dblcmp(this->y, a.y)==0 ? this->x<a.x : this->y < a.y;
	}
	bool operator==(const P& a) const {
		return dblcmp(this->x, a.x)==0 && dblcmp(this->y, a.y)==0;
	}
	double distancePointLine(P& a,P& b){
		return fabs(((*this)-b).cross(a-b)/(a-b).len());
	}
}pts[100005], ans[100005];

ostream &operator<<(ostream &os, const P &p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(2);
	int n,x,y,size, rs, pre, next;
	double mmax, area;
	while (cin >> n && n!=0) {
		mmax = 0;
		for (int i =0; i<n; i++) {
			cin >> x >> y;
			pts[i] = P(x,y);
		}
		sort(pts, pts+n);
		n = unique(pts, pts+n)-pts;
		size = 0;
		for (int i = 0; i<n; i++) {
			while (size>1 && dblcmp((ans[size-1]-ans[size-2]).cross(pts[i]-ans[size-2]), 0)<0) size--;
			ans[size++] = pts[i];
		}
		rs = size;
		for (int i = n-2; i>=0; i--) {
			while (size>rs && dblcmp((ans[size-1]-ans[size-2]).cross(pts[i]-ans[size-2]), 0)<0) size--;
			ans[size++] = pts[i];
		}
		if (n>1) size--;
//		for (int i=0; i<size; i++) {
//			cout << ans[i] << endl;
//		}
		for (int i = 0; i<size; i++) {
			pre = i-1<0? i-1+size : i-1;
			next = i+1>size-1 ? i+1-size : i+1;
			mmax = max(mmax, fabs((ans[pre]-ans[i]).cross(ans[next]-ans[i]))/2.0);
		}
//		cout << mmax << endl;
		ans[size] = ans[0];
		area = 0;
		for (int i = 0; i<size; i++) {
			area+=ans[i+1].cross(ans[i]);
		}
//		cout << area << endl;
		cout << fabs(area)/2.0-mmax << endl;
	}
	return 0;
}
