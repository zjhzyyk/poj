#include <iostream>
#include <string>
using namespace std;

int main(){
	string a, b;
	int i,j,la,lb;
	while (cin >> a >> b) {
		la = a.length();
		lb = b.length();
		i=j=0;
		while (i<la) {
			while (j<lb && b[j]!=a[i]) j++;
			if (j==lb) break;
			i++;
		}
		if (i==la) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}
