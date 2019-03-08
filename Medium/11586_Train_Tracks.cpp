#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int t;

    cin >> t;
    cin.ignore();

    for(int i = 0; i < t; i++){
        string s;
        stringstream ss;

        getline(cin, s);

        if (s.size() == 2){
            cout << "NO LOOP" << endl;
            continue;
        }

        ss << s;

        string subS;

        int contM = 0;
        int contF = 0;
        while (ss >> subS){
            if (subS[0] == 'M' || subS[1] == 'M') contM++;
            if (subS[0] == 'F' || subS[1] == 'F') contF++;
        }

        if (contF == contM) cout << "LOOP";
        else                cout << "NO LOOP";

        cout << endl;
    }
}