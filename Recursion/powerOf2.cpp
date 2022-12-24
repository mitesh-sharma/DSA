#include<iostream>
using namespace std;

int power(int n){
    if(n==0){
        return 1;
    }
    int ans = 2*power(n-1);;
    return ans;
}

int main()
{
    int n;
    cout << "Enter the power of 2: ";
    cin >> n;   

    int ans = power(n);
    cout << "The value of 2 to the power " << n << " is: " << ans << endl;
    return 0;
}