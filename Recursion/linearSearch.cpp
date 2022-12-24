#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int element){
    if(size == 0){
        return false;
    }
    if( arr[0] == element){
        return true;
    }
    else{
        bool ans = linearSearch(arr+1, size-1, element);
        return ans;
    }
}
int main()
{
    int arr[100];
    int size=0;
    int element = 0;
    cout << "Enter the size of the array and element: ";
    cin >> size >> element;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    bool ans = linearSearch(arr, size, element);
    if(ans){
        cout << "Element found " << endl;
    }
    else{
        cout << "Not found " << endl;
    }
    return 0;
}