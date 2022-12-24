#include<iostream>
using namespace std;

class hero{
        string name;
    public:
        int health;
        int exp;

        hero(int health){
            cout  << "1 parameter constructor called: " << endl;
        }
        hero(int health, int exp){
            cout  << "2 parameter constructor called: " << endl;
            this->health = health;
            this->exp = exp;
        }
        void setname(string name){
            this->name = name;
        }
        void getname(){
            cout  << "the name is: " << name << endl;
        }
};


int main()
{
    cout << "Hello, I am Mitesh Sharma " << endl;
    hero h1(100, 80);
    hero h2(10, 20);

    h1.setname("Mitesh");
    h1.getname();
    h1.health = 100;
    cout << "the health of h1 is: " << h1.health << endl;
    h1.exp = 50;
    cout << "the health of h1 is: " << h1.exp << endl;
    h2.setname("tenZ");
    h2.getname();
    h2.health = 40;
    cout << "the health of h2 is: " << h1.health << endl;
    h2.exp = 200;
    cout << "the health of h2 is: " << h1.exp << endl;

    
    return 0;
}