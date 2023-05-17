#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int cnt = i+1;
        for(int j=0; j<n-i-1; j++){
            if(i==0){
                cout << cnt;
            }
            else if(j==0 || j==n-i-2){
                cout << cnt;
            }
            else{
                cout << " ";
            }
            cnt++;
        }
        cout << endl;
    }
    return 0;
}