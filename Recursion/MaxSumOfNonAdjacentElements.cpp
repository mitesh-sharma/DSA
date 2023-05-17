#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector <int> v, int i, int& maxi, int ans){

    if(i>= v.size()){
        maxi = max(maxi, ans);
        return;
    }
    //include
    solve(v, i+2, maxi, ans + v[i]);
    //exclude
    solve(v, i+1, maxi, ans);

}

int main() {
  vector<int> v = {2, 1, 4, 9, 34};
  int maxi = INT_MIN;
  int sum = 0;
  solve(v, 0, maxi, sum);
  cout << maxi << endl;
  return 0;
}