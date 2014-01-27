#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n, in, tmp, o, num;
	cin >> n;
	for (int i = 0; i<n; i++) {
		num = 0;
		cin >> in;
		o = in;
		tmp = in % 2;
		while (tmp!=1) {
			num++;
			in /= 2;
			tmp = in%2;
		}
		cout << o-(1<<num)+1<<" "<<o+(1<<num)-1<<endl;
	}
	return 0;
}