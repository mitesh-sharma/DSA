#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    vector <string> v;
    for(int i=0; i<v.size(); i++){
        cin >> s;
    }
    int ans=0;
    vector <string> a;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<a.size(); j++){
            if(a[j] == v[i]){
                    continue;
                }
                else{
                    a.push_back(v[i]);
                    ans++;
                }
        }
    }
    
    cout << ans;
    return 0;
}