#include<bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int ans1;
	int ans2;
	int x;
	int maxi = -1;
	for (int i = 1; i < n; i++) {
		x = n % i;
		if (x > maxi) {
			maxi = x;
			ans1 = i;
		}
	}
	cout << ans1 << endl;
	maxi = -1;

	for (int i = 1; i < n; i++) {
		int j = 0;
		int cnt = 0;
		while (j < n) {
			cnt++;
			j += i;
		}
		if ((n - cnt) > maxi) {
			ans2 = i;
			maxi = n - cnt;
		}
	}
	cout << ans2 << endl;
	return 0;
}