#include <iostream>
using namespace std;

int f(string s){
    int sum = 0;
    for (unsigned int i = 0; i < s.size(); i++){
        sum += (int) s[i] -48;
    }

    if (sum > 9) return f(to_string(sum));
    else return sum;
}

int main(){
    string n;
    getline(cin, n);

    while (n != "0"){
        cout << f(n) << endl;
        getline(cin, n);
    }
}

