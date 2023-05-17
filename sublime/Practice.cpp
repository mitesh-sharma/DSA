#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int b) {
	int ans;
	int c = 0;
	while (b) {
		ans += (b % 10) * (1 << c++);
		b /= 10;
	}
	return ans;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int row = 5, col = 5;
	vector <vector <int>> vec(row, vector <int> (col, -8));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}