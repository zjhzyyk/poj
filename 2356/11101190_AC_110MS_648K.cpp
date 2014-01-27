#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
bool found = false;
vector<int> ans;
int n;

bool r(int a, int s) {

	s += arr[a];
	if (s % n == 0) {
		return true;
	} else {
		for (int i = a + 1; i < n; i++) {
			if (r(i, s)) {
				ans.push_back(arr[i]);
				return true;
			}
		}
	}
	return false;
}

int main() {
	int in;
	cin >> n;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> in;
		arr[i] = in;
	}
	for (int i = 0; i < n; i++) {
		if (r(i, 0)) {
			ans.push_back(arr[i]);
			break;
		}
	}
	int num = ans.size();
	if (num > 0) {
		cout << num << endl;
		for (int i = 0; i < num; i++)
			cout << ans[i] << endl;
	} else {
		cout << 0;
	}
	return 0;
}
