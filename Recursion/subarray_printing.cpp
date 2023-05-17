#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//MY OWN SOLUTION

void printSubarray(int* arr, int length){
    //base case
    if(length == 0){
        return;
    }

    for(int j=0; j<length; j++){
        for(int k=0; k<=j; k++){
            cout << arr[k] << " "; 
        }
        cout << endl;
    }
    //recursive call
    printSubarray(arr+1, length-1);
}   

int main()
{
    int arr[5] = {1,2,3,4,5};
    int length = sizeof(arr)/sizeof(arr[0]);

    printSubarray(arr, length);

    return 0;
}

//-------------------------------------------------------------------------------------------------
// CODEHELP SOLUTION:


// void PrintFromStartToEnd(vector <int>& v, int start, int end){
//     //base case
//     if(end == v.size()){
//         return;
//     }

//     // ek case
//     for(int i=start; i<=end; i++){
//         cout << v[i] << " ";
//     }
//     cout << endl;
//     //recursive call
//     PrintFromStartToEnd(v, start , end+1);

// }   

// void printSubarray(vector <int>& v){
//     for(int start = 0; start<v.size(); start++){
//         PrintFromStartToEnd(v, start, 0);
//     }
// }

// int main()
// {
//     vector <int> v = {1,2,3,4,5};
//     printSubarray(v);

//     return 0;
// }