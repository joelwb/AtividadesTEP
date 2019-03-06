#include <iostream>
using namespace std;

int main(){
    int n;
    string s;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++){
        getline(cin, s);

        if (s.size() >= 2 && s.substr(s.size() - 2) == "35") cout << "-";
        else if (s[0] == '9' && s[s.size() -1] == '4') cout<< "*";
        else if (s == "1" || s == "4" || s == "78") cout << "+";
        else cout << "?";

        cout << endl;
    }
}