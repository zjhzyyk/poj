#include <iostream>
using namespace std;
int main(){
	double sum = 0;
	double tmp = 0;
	for (int i = 0; i<12; i++) {
		cin >> tmp;
		sum += tmp;
	}
	cout.precision(2);
	cout.setf(ios::fixed);
	cout<<"$"<<sum/12<<endl;
	return 0;
}
