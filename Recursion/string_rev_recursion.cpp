#include <iostream>
using namespace std;
void revstr(string& str, int i){
    int n = str.length()-1;
    if(i>n/2){
        cout << "reversed string is: ";
        return ;
    }
    swap(str[i], str[n-i]);
    revstr(str, i+1);
}
int main(){
    string str = "mitesh";
    string a = str;
    revstr(str, 0);
    cout << str << endl;
    if(str == a){
        cout << "palindrome" << endl;
    }
    else{
        cout << "not a palindrome" << endl;
    }
    return 0;
}