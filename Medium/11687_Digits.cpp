#include <iostream>
using namespace std;

int calc(string s, int n){
    string len = to_string(s.size());
    if (len == s) return n;

    n++;
    return calc(len,n);
}

int main(){
    string s;
    getline(cin, s);

    while(s != "END"){
        cout << calc(s, 1) << endl;
        getline(cin, s);
    }
    
}