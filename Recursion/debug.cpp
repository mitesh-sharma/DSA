#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void permutation(string &ans, string &s, int i, bool &flag){
    if(!flag){
        return;
    }
    else if(i>= s.length()){
        int x = 0;
        for(x=0; x<s.size()-1; x++){
            if(s[x] == s[x+1]){
                break;
            }
        }
        if(x==s.size()-2 && s[x] != s[x+1]){
            ans = s;
            flag = false;
        }
        cout << s << " ";
        return;
    }
    for(int j=i; j<s.length(); j++){
        swap(s[i], s[j]);
        permutation(ans, s, i+1, flag);
        swap(s[i], s[j]);
    }   

}
string reorganizeString(string s) {
    string ans = "";
    int i=0;
    bool flag = true;
    permutation(ans, s, i, flag);
    return ans;
}

int main()
{
    string s = "kkkkzrkatkwpkkkktrq";
    string result = reorganizeString(s);
    if(result == ""){
        cout << "no answer" <<endl;
    }
    else{
        cout << result << endl;
    }
    return 0;
}