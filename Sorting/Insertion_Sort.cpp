#include<iostream>
using namespace std;

void inserts(int arr[], int n){
    int temp;
    int i, j; 
    for (i = 1; i <n; i++)
        temp = arr[i];
        j = i-1; 
        while(j>0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
}
int main(){
    int arr[] = {5,4,10,1,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);     
    for (int i=0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    inserts(arr, n);
    for (int i=0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}