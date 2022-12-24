#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> arr;
    int in = 0;
    for (int i = 0; i < n; i++) {
        cin >> in;
        arr.push_back(in);
    }

    int first = arr[0];
    int minIndex = 0;
    bool x = false;

    while (x == false) {
        int min = INT_MAX;
        //to find min element > first
        for (int j = 1; j < n; j++) {
            if (arr[j] > first && arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        //increment and decrement
        while (first < arr[minIndex]) {
            first++;
            arr[minIndex]--;
        }
        //if all elements are less than or equal to first element, stop
        for (int j = 1; j < n; j++) {
            if (arr[j] <= first) {
                if (j == n - 1) {
                    x = true;
                }
            }
            else {
                break;
            }
        }
    }
    cout << first << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 0;
    cin >> t;
    while (t) {
        solve();
        t--;
    }
    return 0;
}
