#include <iostream>
using namespace std;

int sum = 0;
int fact(int arr[], int size){
    if(size == 0){
        cout << "The sum is: ";
        return sum;
    }
    fact(arr+1, size-1);
    sum = sum+ arr[0];
    return sum;
}

int main(){
    int n=0;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n] = {0};
    for(int i=0; i<n; i++){
        cout << "Enter the element " << i+1 << " ";
        cin >> arr[i];
    }    
    int ans = fact(arr, n);
    cout << ans << endl;
    return 0;
}