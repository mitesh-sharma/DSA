#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// This RECURSIVE SORTING ALGORITHM was written by me trying to implement
//QUICK SORT
void addAtStart(int *a, int pos, int start, int end){
    int element = a[pos];
    if(pos != end){
        for(int i=pos; i<end; i++){
            a[i] = a[i+1];
        }
    }

    for(int i=end; i>start; i--){
        a[i] = a[i-1];
    }
    a[start] = element;
}

void quicksort(int *a, int s, int e){
    if(s>=e){
        return ;
    }
    int pivot = a[s];
    int index = 0;
    for(int i=s+1; i<=e; i++){
        if(pivot >= a[i]){
            addAtStart(a, i, s, e);
        }
    }
    for(int i=s; i<=e; i++){
        if(a[i] == pivot){
            index = i;
        }
    }
    quicksort(a, s, index-1);
    quicksort(a, index+1, e);
}
int main() {
    int arr[5] = {1, 0, 0, 0, -1};
    int length = 5;
    quicksort(arr, 0, length-1);
    for(int i=0; i<length; i++){
        cout << arr[i] << " ";
    }
  return 0;
}