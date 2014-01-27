#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
//	freopen ("in","r",stdin);
	string input,tin;
	int cn;
	int n, dp, l;
	n = 1999;
	char c;
	while (~scanf("Sample input #%d", &cn)){
		dp = 0;
		input = "";
		getline(cin, tin);
		while (getline(cin, tin) && tin!=""){
			input=input + tin;
			if (cin.eof()) break;
		}
//		cout << input << endl;
		l = input.length();
		if (l==0) {
			cout << "Sample output #" << cn << endl << "No" << endl<<endl;
			continue;
		}
//		cout << "length" << l << endl;
		for (int i = 2; i<=l; i++) {
			dp = (dp+n)%i;
		}
		c = input[dp];
//		cout << dp << " " << c << endl;
		switch (c) {
		case '?' : printf("Sample output #%d\nYes\n\n", cn); break;
		case ' ' : printf("Sample output #%d\nNo\n\n", cn); break;
		default : printf("Sample output #%d\nNo comments\n\n", cn); break;
		}
	}
	return 0;
}
