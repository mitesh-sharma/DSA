#include <iostream>
#include<bits/stdc++.h>
using namespace std;


//merging two sorted arrays
void merge(int* a, int s, int e){
    int mid = (s+e)/2;

    //length of left array from s to mid
    int len1 = mid-s+1;

    //length of right array from mid+1 to end
    int len2 = e-mid;

    //filling the leftarr with elements from s to mid
    int* leftarr = new int[len1];
    int k = s;
    for(int i=0; i<len1; i++){
        leftarr[i] = a[k++];
    }

    // filling the rightarr with elements from mid+1 to e
    k = mid + 1;
    int* rightarr = new int[len2];
    for(int i=0; i<len2; i++){
        rightarr[i] = a[k++];
    }

    //using two pointer approach and merging two sorted arrays in a sorted way
    int i=0;
    int j=0;
    int mainIndex = s;
    while(i<len1 && j<len2){
        if(leftarr[i] > rightarr[j]){
            a[mainIndex++] = rightarr[j];
            j++;
        }
        else if(leftarr[i] < rightarr[j]){
            a[mainIndex++] = leftarr[i];
            i++;
        }
        else{
            a[mainIndex++] = leftarr[i];
            a[mainIndex++] = leftarr[i];
            i++;
            j++;
        }
    }
    // after the insertion is done,
    //if one array is larger than other, adding the rest elements of larger array
    // to the resulant array
    while(i<len1){
        a[mainIndex++] = leftarr[i++];
    }
    while(j<len2){
        a[mainIndex++] = rightarr[j++];
    }

}

void mergesort(int* arr, int s, int e){
   if(s>=e){
       return ;
   }
    int mid = (s + e)/2;
    //call for left tree
    mergesort(arr, s, mid);
    //call for right tree
    mergesort(arr, mid+1, e);
    //merging the left and right sub-trees
    merge(arr, s, e);

}

int main() {
    int arr[9] = {43, 21, 11, 78, 90, 27, 19, 100, 50};
    int n = 9;
    mergesort(arr, 0, n-1);
    for(int i=0; i<9; i++){
        cout << arr[i] << " ";
    }

  return 0;
}