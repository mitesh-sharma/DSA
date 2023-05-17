#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void removeAllOccurenceOfChar(string& s, char target, int i){
    //base case
    if(i >= s.size()-1){
        return ;
    }

    if(s[i] == target){
        s.erase(s.begin() + i);
    }
    //recursive call
    removeAllOccurenceOfChar(s, target, i+1);
}

int main()
{
    string s = "abcdefcbdef";
    char target = 'b';

    removeAllOccurenceOfChar(s, target, 0);
    cout << s;
    return 0;
}