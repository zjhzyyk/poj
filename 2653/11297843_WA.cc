#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-8;
bool inTop[100002];
int top[1002];

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
}lines[100002];

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
	int n;
	double a,b,c,d;
	while (scanf("%d", &n) && n!=0) {
		for (int i = 0; i<n; i++) {
			scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
			lines[i]=line(p(a,b), p(c,d));
		}
		for (int i = 0; i<1000; i++) {
			top[i] = i;
			inTop[i] = 1;
		}
		for (int i = 1; i<n; i++){
			for (int j = 0; j<1000 && j<n+1; j++) {
				if (i>top[j] && (overlap(i, top[j]) || intersect(i, top[j]))) {
					if (inTop[i]) top[j] = n+3;
					else {
						top[j] = i;
						inTop[i] = 1;
					}
				}
			}
		}
		sort(top, top+1000);
		cout << "Top sticks: ";
		int i = 0;
		while (top[i]<n) {
			cout << top[i++]+1;
			if (top[i]<n) cout <<", ";
			else {
				cout <<"."<<endl;
				break;
			}
		}
	}
	return 0;
}
