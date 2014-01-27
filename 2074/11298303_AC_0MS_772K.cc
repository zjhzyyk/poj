#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
const double eps=1e-7;

struct segment {
	double x1, x2, y;
	segment(){}
	segment(double a, double b, double c) : x1(a), x2(b), y(c) {}
}house, line, obs;

double calc(double x1, double y1, double x2, double y2, double y3) {
	return (x1-x2)*(y3-y2)/(y1-y2) + x2;
}

int dblcmp(double a, double b){
	if (fabs(a-b) < eps) return 0;
	else return a < b? -1 : 1;
}

int main(){
	double x1, x2, y, ans,last;
	int n;
	bool flag;
	cout.setf(ios::fixed);
	cout.precision(2);
	vector<pair<double, double> > lines;
	while (cin >> x1 >> x2 >> y && !(x1<eps && x2<eps && y<eps)) {
		ans = 0;
		flag = 1;
		house = segment(x1, x2, y);
		cin >> x1 >> x2 >> y;
		line = segment(x1, x2, y);
		cin >> n;
		lines.assign(n, make_pair(0,0));
		for (int i = 0; i<n; i++) {
			cin >> x1 >> x2 >> y;
			if (dblcmp(y, house.y)>0 || dblcmp(y, line.y)<0) continue;
			if (dblcmp(y, line.y)==0) {
				lines[i] = make_pair(x1, x2);
				continue;
			}
			if (dblcmp(y, house.y)==0) {
				if ((dblcmp(x1, house.x1)>0 && dblcmp(x1, house.x2)<0)
					|| (dblcmp(x2, house.x1)>0 && dblcmp(x2, house.x2)<0)) {
					flag = 0;
					break;
				}
				else {
					continue;
				}
			}
			if (!flag) break;
			obs = segment(x1, x2, y);
			lines[i] = make_pair(calc(house.x2,house.y, obs.x1, obs.y,line.y),
					calc(house.x1, house.y, obs.x2, obs.y, line.y));
		}
		if (!flag) {
			cout << "No View" << endl;
			continue;
		}
		sort(lines.begin(), lines.begin()+n);
		last = 0;
		for (int i=0; i<n; i++ ) {
			if (lines[i].first<eps && lines[i].second<eps) continue;
			if (dblcmp(lines[i].first, line.x2)>=0) continue;
			flag = 0;
			if (dblcmp(lines[i].first, last)<=0){
				if (dblcmp(last, lines[i].second) < 0) {
					last = lines[i].second;
				}
			}
			else {
				if (dblcmp(last, line.x2) >=0) break;
				ans=max(ans, lines[i].first-last);
				last = lines[i].second;
			}
			if (dblcmp(last, line.x2) >=0) break;
		}
		if (flag) {
			cout << line.x2-line.x1 << endl;
			continue;
		}
		if (dblcmp(line.x2, last) > 0) ans = max(ans, line.x2-last);
		if (ans<eps) cout << "No View" << endl;
		else cout << ans << endl;
	}
	return 0;
}
