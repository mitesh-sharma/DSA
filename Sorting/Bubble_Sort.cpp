#include <iostream>
using namespace std;

void swapp(int *a1, int *a2){
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
void bubble(int arr[], int n){
    
    int i, j; 
    for (i = 0; i < n-1; i++)     
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
            swapp(&arr[j], &arr[j+1]);
}

int main(){
    int arr[] = {1, 4, 67, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);     
    for (int i=0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    bubble(arr, n);
    for (int i=0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
