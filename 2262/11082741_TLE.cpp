#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
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
	int property[500000];
	vector<int> primes;
	memset(property, 0, sizeof(property));
	for (int i = 1; i < 500000; i++) {
		if (property[i] != 1) {
			if (isPrime(2*i+1)) {
				property[i] = 2; //is prime;
				primes.push_back(2*i+1);
				tmp = (2*i + 1)*3;
				while (tmp < 1000000) {
					property[(tmp-1)/2] = 1; // not prime
					tmp += 2*(2*i+1);
				}
			}
		}
	}
	cin >> n;
	int j, num = primes.size();
	bool found;
	while (n != 0) {
		found = false;
		for (j = 0;j<num && (n-primes[j])>=n/2;j++) {
			if (property[((n-primes[j])-1)/2]==2) {
				cout << n << " = " << primes[j] << " + " << (n-primes[j])<< endl;
				found = true;
				break;
			}
		}
		if (!found) cout << "Goldbach's conjecture is wrong."<<endl;
		cin>>n;
	}
	return 0;
}
