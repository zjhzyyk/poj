#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool isPrime(int n) {
	int sr = sqrt((double)n);
	if (n==2) return true;
	for (int i = 2; i <= sr; i++)
		if (n % i == 0)
			return false;
	return true;
}
int main() {
	int n, tmp;
	int property[1000000];
//	vector<int> primes(20000);
	memset(property, 0, sizeof(property));
	for (int i = 2; i < 1000000; i++) {
		if (property[i] != 1) {
			if (isPrime(i)) {
				property[i] = 2; //is prime;
//				primes.push_back(i);
				tmp = i + i;
				while (tmp < 1000000) {
					property[tmp] = 1; // not prime
					tmp += i;
				}
			}
		}
	}
	cin >> n;
	while (n != 0) {
		for (int i = 3; i<1000000; i++) {
			if (property[i]==2 && property[n-i]==2) {
				cout << n << " = " << i << " + " << (n-i)<< endl;
				break;
			}
		}
		cin>>n;
	}
	return 0;
}
