#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-8;
bool isTop[100000];

struct p{
	double x, y;
	p(){}
	p(double a, double b) : x(a), y(b) {}
	p operator- (const p& a){
		return p(this->x-a.x, this->y-a.y);
	}
	double operator* (const p& a) {
		return this->x*a.x+this->y*a.y;
	}
	double dist (const p& a) {
		return ((*this)-a)*((*this)-a);
	}
	double cross (const p& a) {
		return this->x*a.y-this->y*a.x;
	}
};

struct line {
	p start, end;
	line(){}
	line(p a, p b): start(a), end(b) {}
}lines[100000];

bool intersect(int i, int j){
	p& a = lines[j].start;
	p& b = lines[j].end;
	p& c = lines[i].start;
	p& d = lines[i].end;
	if ((a-b).cross(a-c) * (a-b).cross(a-d) < 0
		&& (c-d).cross(c-a) * (c-d).cross(c-b) < 0)
		return true;
	else
		return false;
}

bool overlap(int i, int j){
	p& a = lines[j].start;
	p& b = lines[j].end;
	p& c = lines[i].start;
	p& d = lines[i].end;
	if (fabs((a-b).cross(a-c))<eps &&
		fabs((a-b).cross(a-d))<eps &&
		((c-a)*(c-b) < 0 || (d-a)*(d-b)<0))
		return true;
	else return false;
}

int main(){
	int n, num;
	double a,b,c,d;
	while (scanf("%d", &n) && n!=0) {
		num = n;
		for (int i = 0; i<n; i++) {
			isTop[i] = 1;
			scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
			lines[i]=line(p(a,b), p(c,d));
			for (int j = 0; j<i; j++) {
				if (isTop[j] && (intersect(i,j) || overlap(i,j))) {
					isTop[j] = 0;
					num--;
				}
			}
		}
		cout << "Top sticks: ";
		for (int i = 0; i< n; i++) {
			if (isTop[i]) {
				cout << i+1;
				num--;
				if (!num) cout <<"."<<endl;
				else cout <<", ";
			}
		}
	}
	return 0;
}
