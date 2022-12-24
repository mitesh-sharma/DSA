#include<iostream>
using namespace std;

void counting(int n){
    if(n==0){
        return;
    }
    counting(n-1);
    cout << n << " ";
}

int main()
{
    int n=0;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "the counting is: ";
    counting(n);
    return 0;
}