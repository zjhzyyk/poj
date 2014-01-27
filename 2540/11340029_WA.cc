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

int cnt;

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
	bool operator==(const P& a) const {
		return dblcmp(this->x, a.x)==0 && dblcmp(this->y, a.y)==0;
	}
	double distancePointLine(P& a,P& b){
		return fabs(((*this)-b).cross(a-b)/(a-b).len());
	}
}p[65],q[65], pre, tmp;

P intersect(P& a,P& b,P& c,P& d) {
	return a + (b-a)*((d-c).cross(a-c)/(d-c).cross(a-b));
}

struct line{
	P from, to;
	int dir;
};

double area() {
	double ret = 0;
	p[cnt] = p[0];
	for (int i = 0; i<cnt; i++) {
		ret+=p[i+1].cross(p[i]);
	}
	return fabs(ret)/2.0;
}

line getline(P& np, int coeff){
	line ret;
	P orig = np-pre;
	ret.from = pre + orig*0.5;
	ret.to = ret.from+P(-1*orig.y, orig.x);
	ret.dir = coeff * dblcmp( (np-ret.from).cross(ret.to-ret.from) , 0);
	pre = np;
	return ret;
}

void cut(line l) {
	int curcnt = 0;
	int curdir;
	int pre, next;
	P ldir = l.to-l.from;
	for (int i = 0; i<cnt; i++) {
		curdir = dblcmp((p[i]-l.from).cross(ldir), 0);
		if (curdir==0 || curdir==l.dir) {
			q[curcnt++] = p[i];
		}
		else {
			pre = i-1<0 ? i-1+cnt : i-1;
			next = i+1<cnt ? i+1 : i+1-cnt;
			if (dblcmp((p[pre]-l.from).cross(ldir), 0)==l.dir)
				q[curcnt++] = intersect(p[pre], p[i], l.to, l.from);
			if (dblcmp((p[next]-l.from).cross(ldir), 0)==l.dir)
				q[curcnt++] = intersect(p[next], p[i], l.to, l.from);
		}
	}
	for (int i = 0; i<curcnt; i++) {
		p[i] = q[i];
	}
	cnt = curcnt;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(2);
	double x, y;
	string in;
	pre = P(0,0);
	cnt = 4;
	bool flag = 0;
	p[0] = P(0,0);
	p[1] = P(10,0);
	p[2] = P(10,10);
	p[3] = P(0,10);
	while (cin >> x >> y >> in) {
		if (flag) {
			cout << 0 << endl;
			continue;
		}
		P np = P(x,y);
		if (in=="Colder")
			cut(getline(np, -1));
		else if (in=="Hotter")
			cut(getline(np, 1));
		else {
			cout << 0 << endl;
			flag = 1;
			continue;
		}
		cout << area() << endl;
	}
	return 0;
}
