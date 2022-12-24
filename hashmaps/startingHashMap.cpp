#include<iostream>
#include <map>
#include<unordered_map>

using namespace std;

int main()
{
    //creation
    unordered_map<string, int> m;

    //insertion
    pair<string, int> p = make_pair("Mitesh", 3);
    m.insert(p);

    //2
    pair<string, int> p2("hello", 1);
    m.insert(p2);

    //3
    m["wassup"] = 1;

    //searching
    cout << m["Mitesh"] << endl;
    cout << m.at("Mitesh") << endl;

    // returns 0 or 1 based on the presence of the object
    cout << m.count("bro") << endl;

    //traversing
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    //2 using iterator
    unordered_map <string, int> :: iterator it = m.begin();

    while(it !=m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}