#include<iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(vector <int> v, pair <int, int>& p, int i){
    if(i == v.size()){
        return {0,0};
    }
    if(v[i]%2 == 0){
        p.first += v[i];
    }
    if(v[i]%2 != 0){
        p.second += v[i];
    }
    solve(v, p, i+1);
    return p;
}

int main()
{
    pair <int, int> p = {0,0}; 
    vector <int> v = {2,3,6,7,1,9,34};
    solve(v, p, 0);
    cout << p.first << " " << p.second << endl;
    return 0;
}