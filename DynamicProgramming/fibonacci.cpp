#include<iostream>
#include <bits/stdc++.h>
using namespace std;

    int topDown(int n, vector <int>& dp){
        //base case
        if(n==0 || n==1){
            return n;
        }
        //check if answer already exists
        if(dp[n] != -1){
            return dp[n];
        }
        //replace ans with dp[n]
        dp[n] = topDown(n-1, dp) + topDown(n-2, dp);
        return dp[n];
    }

    // Tabulation method
    int bottomUp(int n){
        //create DP array
        vector <int> dp(n+1, -1);
        //Base case
        dp[0] = 0;
        if(n==0){
            return 0;
        }
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int so(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        int prev1 = 1;
        int prev2 = 0;
        int curr = 0;
        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    // vector <int> dp(n+1, -1);
    // int ans = topDown(n, dp);
    // int ans = bottomUp(n);
    int ans = so(n);
    cout << "term at index "<< n << " is: " << ans;
    return 0;
}