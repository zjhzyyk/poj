#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int array[500005], num, ans;

int loc[500005];

void merge(int fr, int mid, int to) {
	int out = 0;  // index for loading loc array
	int left = fr;  // index on left half
	int rt = mid+1;  // index on right half
	while(left <= mid && rt <= to ) {
		if(array[left] < array[rt]) {
			loc[out++] = array[left++];
		} else {
			loc[out++] = array[rt++];
			ans+=(mid-left+1);
		}
	}
	while(left <= mid) loc[out++] = array[left++];
	while(rt <= to) loc[out++] = array[rt++];
	for(int i = 0; i < out; i++) {
		array[fr+i] = loc[i];
	}
}

void mergeSort(int fr, int to) {
	if(to > fr) {
		int mid = (to + fr)/2;
		mergeSort(fr, mid);
		mergeSort(mid+1, to);
		merge(fr, mid, to);
	}
}

int main(){
	while (cin >> num && num) {
		ans = 0;
		for (int i=0; i<num; i++) cin >> array[i];
		mergeSort(0, num-1);

		cout << ans << endl;
	}
	return 0;
}
