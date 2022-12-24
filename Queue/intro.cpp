#include<iostream>
#include <queue>
using namespace std;

int main()
{
    queue <int> q;

    q.push(1);
    cout << "front of queue is: " << q.front() << endl;
    q.front()+=1;
    q.push(2);
    cout << "front of queue is: " << q.front() << endl;
    q.push(3);
    cout << "front of queue is: " << q.front() << endl;
    q.push(4);
    cout << "front of queue is: " << q.front() << endl;

    cout << "size of queue is: " << q.size() << endl;

    q.pop();
    q.pop();

    cout << "size of queue is: " << q.size() << endl;

    q.empty() ? cout << "empty" << endl : cout << "not empty" << endl;
    return 0;
}