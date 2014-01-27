#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
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
	int id;
	bool upward;
	bool peak;
	P(){peak = 0;}
	P(double a, double b) {x=a; y=b;peak = 0;}
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

void findupward(int start, int end, int cur, vector<P>& ret){
	ret.clear();
	for (int j = start; j <= end; j++) {
		if (j==cur) continue;
		while (ret.size()>1 &&
				dblcmp((ret[ret.size()-1]-ret[ret.size()-2]).cross(pts[j]-ret[ret.size()-2]), 0)<0)
			ret.pop_back();
		ret.push_back(pts[j]);
	}
}

void finddownward(int end, int start, int cur, vector<P>& ret) {
	ret.clear();
	for (int j = end; j>=start; j--) {
		if (j==cur) continue;
		while (ret.size()>1 &&
				dblcmp((ret[ret.size()-1]-ret[ret.size()-2]).cross(pts[j]-ret[ret.size()-2]), 0)<0)
			ret.pop_back();
		ret.push_back(pts[j]);
	}
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(2);
	int n,x,y,size, rs, pre, next,ts;
	double mmax, area, tmparea;
	vector<P> tmp;
	while (cin >> n && n!=0) {
		mmax = 0;
		for (int i =0; i<n; i++) {
			cin >> x >> y;
			pts[i] = P(x,y);
		}
		sort(pts, pts+n);
		n = unique(pts, pts+n)-pts;
		for (int i = 0; i<n; i++) {
			pts[i].id = i;
		}
		size = 0;
		for (int i = 0; i<n; i++) {
			while (size>1 && dblcmp((ans[size-1]-ans[size-2]).cross(pts[i]-ans[size-2]), 0)<0) size--;
			ans[size++] = pts[i];
			ans[size-1].upward = 1;
		}
		ans[size-1].peak = 1;
		rs = size;
		for (int i = n-2; i>=0; i--) {
			while (size>rs && dblcmp((ans[size-1]-ans[size-2]).cross(pts[i]-ans[size-2]), 0)<0) size--;
			ans[size++] = pts[i];
			ans[size-1].upward = 0;
		}
		if (n>1) size--;
//		for (int i=0; i<size; i++) {
//			cout << ans[i] << endl;
//		}
		for (int i = 0; i<size; i++) {
			tmparea = 0;
			pre = i-1<0? i-1+size : i-1;
			next = i+1>size-1 ? i+1-size : i+1;
			if (i==0) {
				finddownward(ans[pre].id, 0, ans[i].id, tmp);
				ts = tmp.size();
				for (int j = tmp[tmp.size()-1].id+1; j<= ans[next].id; j++){
					if (j==ans[i].id) continue;
					while (tmp.size() > ts &&
							dblcmp((tmp[tmp.size()-1]-tmp[tmp.size()-2]).cross(pts[j]-tmp[tmp.size()-2]), 0)<0)
						tmp.pop_back();
					tmp.push_back(pts[j]);
				}
			} else if (ans[i].peak) {
				findupward(ans[pre].id, ans[i].id, ans[i].id, tmp);
				ts = tmp.size();
				for (int j = tmp[tmp.size()-1].id-1; j>=ans[next].id; j--) {
					if (j==ans[i].id) continue;
					while (tmp.size()>ts &&
							dblcmp((tmp[tmp.size()-1]-tmp[tmp.size()-2]).cross(pts[j]-tmp[tmp.size()-2]), 0)<0)
						tmp.pop_back();
					tmp.push_back(pts[i]);
				}
			}else {
				if (ans[i].upward)
					findupward(ans[pre].id, ans[next].id, ans[i].id,tmp);
				else
					finddownward(ans[pre].id, ans[next].id, ans[i].id,tmp);
			}
//			cout << "partial hull of " << ans[i] << endl;
//			for (int j = 0; j<tmp.size(); j++) {
//				cout << tmp[j] << endl;
//			}
			tmp.push_back(ans[i]);
			tmp.push_back(tmp[0]);
			for (int j =0; j<tmp.size()-1; j++) {
				tmparea += tmp[j+1].cross(tmp[j]);
			}
//			cout << "tmparea " << fabs(tmparea)/2.0 << endl;
			mmax = max(mmax, fabs(tmparea)/2.0);
//			cout << "cur mmax" << mmax << endl;
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
