#include <iostream>
using namespace std;

int main() {
	int ans[31] = {1,0,3,0};
	int tmp;
	for (int i = 4; i<31; i++) {
		ans[i]  = ans[i-2]*3+ans[i-4]*2;
		tmp = i-6;
		while (tmp>=0) {
			ans[i] += ans[tmp]*2;
			tmp-=2;
		}

	}
	int n;
	while (cin >> n && n!= -1) {
		cout << ans[n]<<endl;
	}
	return 0;
}
