#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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
		return this->y==a.y ? this->x<a.x : this->y < a.y;
	}
	//**
	//*distance from this point to the line which passes point a and point b
	double distancePointLine(P& a,P& b){
		return ((*this)-b).cross(a-b)/(a-b).len();
	}
};

vector<P> p;

int main(){
	int n,pre,cur,count;
	bool flag;
	double r,x,y,a,b;
	P center;
	while (cin >> n && n>=3) {
		cin>> r >> x >> y;
		flag = 1;
		count = 0;
		center = P(x,y);
		p.assign(n+2, P());
		for (int i = 0; i<n; i++) {
			cin >> a >> b;
			p[i] = P(a,b);
		}
		p[n] = p[0];
		pre = dblcmp((p[1]-p[0]).cross(p[n-1]-p[0]), 0);
		for (int i = 1; i<n; i++) {
			cur = dblcmp((p[i+1]-p[i]).cross(p[i-1]-p[i]),0);
			if (cur!=pre && pre!=0 && cur!=0) {
				flag = false;
				break;
			}
			if (pre==0) {
				pre = cur;
				count++;
			}
		}
		if (count>n-3) flag = false;
		if (!flag) {
			cout << "HOLE IS ILL-FORMED" << endl;
			continue;
		}
		pre = dblcmp((center-p[0]).cross(p[1]-p[0]), 0);
		for (int i = 1; i<n; i++) {
			cur = dblcmp((center-p[i]).cross(p[i+1]-p[i]), 0);
			if (pre * cur < 0 ) {
				flag = false;
				break;
			}
			if (pre == 0) pre = cur;
		}
		for (int i = 0; i<n && flag; i++) {
			if (dblcmp(r, center.distancePointLine(p[i], p[i+1]))>0) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << "PEG WILL NOT FIT" << endl;
		}
		else cout << "PEG WILL FIT" << endl;
	}

	return 0;
}
