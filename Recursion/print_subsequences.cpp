#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str, string output, int i, vector <string>& v){
    if(i == str.size()){
        v.push_back(output);
        return;
    }
    //include
    printSubsequences(str, output + str[i], i+1, v);
    //exclude
    printSubsequences(str, output, i+1,v);
}

int main() {
  string str = "mitesh";
  string output = "";
  vector <string> v;
  int i=0;
  printSubsequences(str, output, i, v);
  for(auto i: v){
      cout << i << " ";
  }
  return 0;
}