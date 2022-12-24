#include <iostream>
using namespace std;

void func(int &n){
    int*p = &n;
    n = n +3;
    cout << p << endl;
} 
int main(){
    int i=5;
    cout << "before" << i << endl;
    func(i);
    cout << "after" << i << endl;
    return 0;
}