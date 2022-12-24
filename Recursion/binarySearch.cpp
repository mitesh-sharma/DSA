#include<iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int element){
    if(s > e){
        return false;
    }
    int mid = s+(e-s)/2;
    if(arr[mid] == element){
        return true;
    }
    bool ans;
    if(s > e){
        return false;
    }
    if(element > arr[mid]){
        return binarySearch(arr, mid+1, e, element);
    }
    else{
        return binarySearch(arr, s, mid-1, element);
        
    }
}

int main()
{
    int arr[] = {0, 2, 3, 45, 6};
    int element = 1;

    if(binarySearch(arr, 0, 6,element)){
        cout << "Element found" <<endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    return 0;
}