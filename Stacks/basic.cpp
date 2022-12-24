#include<iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
   

    if(s.empty()){
        cout << "stack is empty " <<endl;
    }
    else{
    cout << s.top() << endl;
    }
    cout << s.size() << endl;

    return 0;
}