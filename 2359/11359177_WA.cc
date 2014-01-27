#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string input,tin;
	int cn;
	int n, dp, l;
	char c;
	while (~scanf("Sample input #%d", &cn)){
		dp = 0;
		getline(cin, tin);
		n = 1999;
		getline(cin, input);
		while (getline(cin, tin) && tin!=""){
			input=input + tin;
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
