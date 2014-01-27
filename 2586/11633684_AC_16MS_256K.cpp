#include <iostream>
using namespace std;

int main(){
	double s,d;
	int ans;
	while (cin >> s >> d) {
		if (s<d/4.0){
			ans = 10*s-2*d;
			if (ans>0)
				cout << ans << endl;
			else cout << "Deficit" << endl;
		}
		else if (s<d*2.0/3.0) {
			ans = 8*s-4*d;
			if (ans>0)
				cout << ans << endl;
			else cout << "Deficit" << endl;
		}
		else if (s<d*3.0/2.0) {
			ans = 6*s-6*d;
			if (ans>0)
				cout << ans << endl;
			else cout << "Deficit" << endl;
		}
		else if (s<4.0*d) {
			ans = 3*s-9*d;
			if (ans>0)
				cout << ans << endl;
			else cout << "Deficit" << endl;
		}
		else
			cout << "Deficit" << endl;
	}
	return 0;
}
