#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int oddsize;
  cin >> oddsize;

  int evensize;
  cin >> evensize;

  vector <int> odd;
  vector <int> even;
  for(int i=0; i<oddsize; i++){
      int temp;
      cin >> temp;
      odd.push_back(temp);
  }
  for(int i=0; i<evensize; i++){
      int temp;
      cin >> temp;
      even.push_back(temp);
  }
  int ele;
  cout << "enter the middle element: ";
  cin >> ele;

  int i = 0;
  int j = odd.size()-1;
  while(i<=j){
    if(i==j){
      cout << odd[i] << " " << ele << endl;
    }
    else{
      cout << odd[i] << " " << odd[j] << endl;
    }
    i++;
    j--;
  }
  cout << endl <<endl;
  i=0;
  j=even.size()-1;
   while(i<j){
      cout << even[i] << " " << even[j] << endl;
    i++;
    j--;
  }
  return 0;
}