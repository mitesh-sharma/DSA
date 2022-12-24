#include <iostream>
using namespace std;
int main(){
    int a {0};
    int nums[5];
    int numsize = sizeof(nums)/sizeof(nums[0]);
    for (int x=0; x<=numsize; x++){
        cin >> nums[x];
    }
    for (int y=0; y<=numsize; y++){
        cout << nums[y] << " ";
    }
    for(int i=0; i<=numsize; i++){
        for(int j=i+1; j <=numsize; j++){
            if(nums[i]==nums[j]){
                a = a+1;
            }
        }
    }
    if(a>=1){
        cout << endl << "true" << endl;
    }
    else{
        cout << endl << "false" << endl;
    }
    return 0;
}