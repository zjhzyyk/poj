#include <iostream>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535
#define PRECISION 1e-4
#define EPS 1e-9
using namespace std;

int dblcmp(double a, double b) {
	if (abs(a-b)<EPS) return 0;
	else return a < b ? -1 : 1;
}

int main(){
	double l, n, c, ll, newl, low, high, mid, dif, pre, cur;
	cout.setf(ios::fixed);
	cout.precision(3);
	while (cin >> l >> n >> c && dblcmp(l, 0)>=0 && dblcmp(n, 0)>=0 && dblcmp(c, 0)>=0) {
		low = 0;
		high = PI;
		dif = 1;
		while (dif > PRECISION) {
			mid = (low+high) / 2;
			ll = l * mid / sin(mid);
			newl = (1+n*c)*l;
			pre = newl*(1-cos(mid))/(2*mid);
			if (abs(ll-newl)<EPS) break;
			if (ll<newl) {
				low = mid;
				mid = (mid+high)/2;
			}
			if (ll>newl) {
				high = mid;
				mid = (low+mid)/2;
			}
			cur = newl*(1-cos(mid))/(2*mid);
			dif = abs(pre-cur);

		}
		cout << cur << endl;
	}

	return 0;
}
