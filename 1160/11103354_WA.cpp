#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#define MAXINT 2147483647
using namespace std;

int main() {
	int vn, pn, min = MAXINT;
	cin >> vn >> pn;
	bool has[300];
	int c[300][2];
	memset(has, false, sizeof(has));
	int total, choose;
	for (int i = 0; i < vn; i++) {
		cin >> c[i][0];
		c[i][1] = MAXINT;
	}
	for (int i = 1; i <= pn; i++) {
		//i-pn
		for (int j = 0; j < vn; j++) {
			//pick one
			if (has[j])
				continue;
			else {
				//determine which to choose
				total = 0;
				for (int k = 0; k < vn; k++) {
					if (c[k][1] > abs(c[k][0] - c[j][0]))
						total += abs(c[k][0] - c[j][0]);
					else
						total += c[k][1];
				}
				if (total < min) {
					min = total;
					choose = j;
				}
			}
		}
		has[choose] = true;
		//update
		for (int k = 0; k < vn; k++) {
			if (c[k][1] > abs(c[k][0] - c[choose][0]))
				c[k][1] = abs(c[k][0] - c[choose][0]);
		}
	}
	cout << min << endl;
	return 0;
}
