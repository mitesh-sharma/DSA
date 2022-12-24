#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr+1, size-1);
        return ans;
    }
}
int main()
{
    int arr[10000];
    int size=0;
    cout << "Enter the size of the array: ";
    cin >> size;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    if(isSorted(arr, size)){
        cout << " The array is sorted " << endl;
    }
    else{
        cout << " Not sorted" << endl;
    }
    return 0;
}