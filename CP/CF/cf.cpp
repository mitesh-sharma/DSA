#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	// vector <bool> dp(n + 1, 0);
	// dp[0] = 1;

	// for (int i = 0; i <= n; i++) {
	// 	if (i - 2020 >= 0 && i - 2021 >= 0) {
	// 		dp[i] = dp[i - 2020] || dp[i - 2021];
	// 	}
	// }
	// return dp[n];
	int n;
	cin >> n;
	while (n > 0) {
		if (n % 2020 != 0) {
			n -= 2021;
		}
		else {
			n -= 2020;
		}
	}
	if (n == 0) {
		cout << "YES" << endl;
	}
	else if (n < 0) {
		cout << "NO" << endl;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("cfinput.txt", "r", stdin);
	freopen("cfoutput.txt", "w", stdout);
#endif
	int t = 0;
	cin >> t;
	while (t) {
		solve();
		t--;
	}

	return 0;
}