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

}p[33][33];

ostream &operator<<(ostream &os, const P &p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

P intersect(P& a,P& b,P& c,P& d) {
	return a + (b-a)*((d-c).cross(a-c)/(d-c).cross(a-b));
}

double area(P& a,P& b,P& c,P& d) {
	return fabs((b-c).cross(a-c))/2.0 + fabs((b-c).cross(d-c))/2.0;
}

int main(){
	int n;
	p[0][0] = P(0,0);
	double tmp,mmax;
	cout.setf(ios::fixed);
	cout.precision(6);
	while (cin >> n && n!=0) {
		mmax= 0;
		for (int i = 0; i<4; i++) {
			for (int j = 0 ; j<n; j++) {
				cin >> tmp;
				switch (i) {
				case 0: p[0][j+1] = P(tmp, 0); break;
				case 1: p[n+1][j+1] = P(tmp, 1); break;
				case 2: p[j+1][0] = P(0, tmp); break;
				case 3: p[j+1][n+1] = P(1, tmp); break;
				}
			}
		}
		p[0][n+1] = P(1,0);
		p[n+1][0] = P(0,1);
		p[n+1][n+1] = P(1,1);
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				p[i+1][j+1] = intersect(p[i+1][0], p[i+1][n+1], p[0][j+1], p[n+1][j+1]);
			}
		}

		for (int i = 0; i<n+1; i++) {
			for (int j = 0; j<n+1; j++) {
				mmax = max(mmax, area(p[i][j], p[i][j+1], p[i+1][j], p[i+1][j+1]));
			}
		}
		cout << mmax << endl;
	}
	return 0;
}
