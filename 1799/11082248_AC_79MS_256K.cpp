#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int casen;
	cin >> casen;
	double r;
	int n;
	double ans;
	double pi = 3.1415926535;
	double theta;
	cout.setf(ios::fixed);
	cout.precision(3);
	for (int i = 0; i<casen; i++) {
		cin >> r >> n;
		theta = pi/n;
		ans = (r*sin(theta))/(1+sin(theta));
		cout << "Scenario #" << i+1 << ":" << endl << ans << endl<<endl;
	}
	return 0;
}
