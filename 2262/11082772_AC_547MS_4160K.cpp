#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int primes[1000000];
	memset(primes, 0, sizeof(primes));
	int i, j;
	for (i = 2; i < 1000000; i++)
		if (!primes[i])
			for (j = 2; i * j < 1000000; j++)
				primes[j * i] = 1;
	primes[0] = primes[1] = 1;
	int n;
	cin >> n;
	while (n != 0) {
		for (i = 3; i <= n / 2; i += 2)
			if (primes[i] == 0 && primes[n - i] == 0) {
				cout << n << " = " << i << " + " << (n-i)
						<< endl;
				break;
			}
		if (i > n / 2)
			cout << "Goldbach's conjecture is wrong." << endl;
		cin >> n;
	}
	return 0;
}
