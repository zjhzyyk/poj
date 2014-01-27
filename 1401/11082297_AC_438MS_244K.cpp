#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int num;
	int div = 5;
	int in;
	int sum;
	for (int i = 0; i<n; i++) {
		sum = 0;
		num = 1;
		div = 5;
		cin>>in;
		while (num!=0) {
			num = in/div;
			sum+=num;
			div = div*5;
		}
		cout<<sum<<endl;
	}
	return 0;
}
