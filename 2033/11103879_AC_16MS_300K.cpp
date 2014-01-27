#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string in;
	int s;
	while (cin >> in && in != "0") {
		s = in.length();
		vector<long> ans(s, 0);
		ans[0] = 1;
		if ((10*((char)in[0]-'0')+(char)in[1]-'0') > 26 || (char)in[1]-'0'==0)
		ans[1] = 1;
		else ans[1] = 2;
		for (int i = 2; i<s; i++) {
			if ((10*((char)in[i-1]-'0')+(char)in[i]-'0')>26 || (char)in[i-1]-'0'==0)
			ans[i] = ans[i-1];
			else if ((char)in[i]-'0'<=0) ans[i] = ans[i-2];
			else ans[i] = ans[i-1]+ans[i-2];
		}
		cout << ans[s-1]<<endl;
	}
	return 0;
}
