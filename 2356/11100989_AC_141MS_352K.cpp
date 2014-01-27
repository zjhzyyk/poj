#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

void p(int a, int b) {
	cout << b-a+1<<endl;
	for(int i = a; i<b+1; i++) cout << arr[i] << endl;
}

int main()
{
	int n,in,r, sum = 0;
	cin >> n;
	arr.assign(n,0);
	vector<int> rem(n,-1);
	for (int i = 0; i<n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (int i=0; i<n; i++) {
		sum += arr[i];
		r = sum % n;
		if (r == 0) {p(0,i); return 0;}
		else if (rem[r] != -1) {p(rem[r]+1, i); return 0;}
		else rem[r] = i;
	}
    return 0;
}
