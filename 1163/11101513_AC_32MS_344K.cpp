#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int row, m = 0;
	cin >> row;
	int numbers[100][100][2];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> numbers[i][j][0];
		}
	}
	numbers[0][0][1] = numbers[0][0][0];
	for (int i = 1; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			if (j==0) numbers[i][j][1] = numbers[i-1][j][1] + numbers[i][j][0];
			else if (j == i) numbers[i][j][1] = numbers[i-1][j-1][1] + numbers[i][j][0];
			else numbers[i][j][1] = max(numbers[i-1][j-1][1], numbers[i-1][j][1]) + numbers[i][j][0];
		}
	}
	for (int i = 0; i<row; i++) {
		if(numbers[row-1][i][1] > m) m =numbers[row-1][i][1];
	}
	cout << m;
	return 0;
}
