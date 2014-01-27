#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const double eps = 1e-8;
const int inf = 0x7fffffff;

int size,n;

int dblcmp(double a, double b) {
	if (fabs(a-b)<eps) return 0;
	else return a<b? -1 : 1;
}

struct P {
	double x, y;
	int id;
	P(){}
	P(double a, double b) {x=a; y=b;}
	P operator+ (const P& a) {
		return P(this->x+a.x, this->y+a.y);
	}
	P operator- (P& a){
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
	double dissqr(const P& a) {
		return (this->x-a.x)*(this->x-a.x) + (this->y-a.y)*(this->y-a.y);
	}
}pts[100005], ans[100005], bp;

bool polarCmp(P a, P b) {
	int u = dblcmp((a-bp).cross(b-bp), 0);
	return u > 0 || (u==0 && dblcmp(bp.dissqr(a), bp.dissqr(b))<0);
}

void calc(int k, vector<P>& ret){
	ret.clear();
	int j,tmp;
	bool flag = 0;
	int start = ans[k-1].id;
	ret.push_back(pts[start]);
	j = start+1==ans[k].id ? start+2 : start+1;
	ret.push_back(pts[j++]);
	tmp = j;
	int i = 1;
	for (;;j++) {
		if (k==size-1 && j>=n) {
			flag = 1;
			j = j%n;
		}
		if (k!=size-1 && j>ans[k+1].id) break;
		if (k==size-1 && flag && j > ans[k+1].id) break;
		if (j==ans[k].id) continue;
		while (i>0 && dblcmp((ret[i]-ret[i-1]).cross(pts[j]-ret[i-1]), 0) < 0 ) i--;
		ret[++i] = pts[j];
	}
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(2);
	int x,y,k;
	double total,mmax, area;
	vector<P> nps;
	while (cin >> n && n!=0) {
		total = 0;
		mmax = 0;
		k = 0;
		for (int i =0; i<n; i++) {
			cin >> x >> y;
			pts[i] = P(x,y);
			if (pts[i] < pts[k]) k =i;
		}
		bp = pts[k];
		sort(pts, pts+n, polarCmp);
		n = unique(pts, pts+n)-pts;
		pts[n] = pts[0];
		pts[n+1] = pts[1];
		for (int i =0; i<n; i++) pts[i].id = i;
		if (n<=1) {
			cout << "0.00" << endl;
			continue;
		}
		if (dblcmp((pts[1]-pts[0]).cross(pts[n-1]-pts[0]), 0)==0) {
			cout << "0.00" << endl;
			continue;
		}
		ans[0] = pts[0];
		ans[1] = pts[1];
		int i = 1;
		for (int j = 2; j<n; j++) {
			while (i>0 && dblcmp((ans[i]-ans[i-1]).cross(pts[j]-ans[i-1]), 0) < 0 ) i--;
			ans[++i] = pts[j];
		}
		size = i+1;
		ans[++i] = ans[0];
		ans[++i] = ans[1];
		for (int k = 0; k<size; k++) {
			total += ans[k+1].cross(ans[k]);
		}
		total = fabs(total)/2.0;
		for (int k = 1; k<size+1; k++) {
			calc(k, nps);
			nps.push_back(ans[k]);
			nps.push_back(nps[0]);
			area = 0;
			for (int j = 0; j<nps.size()-1; j++) {
				area+=nps[j+1].cross(nps[j]);
			}
			area = fabs(area)/2.0;
			mmax = max(mmax, area);
		}
		cout << total-mmax << endl;
	}
	return 0;
}
