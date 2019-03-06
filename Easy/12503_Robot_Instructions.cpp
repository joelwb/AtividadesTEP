#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int makeMove(string s, vector<string> ss){
    if (s == "LEFT") return -1;
    else if (s == "RIGHT") return 1;
    else {
        stringstream stream;
        stream << s;
        string aux;

        stream >> aux >> aux >> aux;
        return makeMove(ss[stoi(aux) - 1], ss);
    }
}

int main(){
    int T, n, p = 0;
    vector<string> instrutions;
    string instrution;

    cin >> T;
    for (int i = 0; i < T; i++){
        p = 0;
        instrutions.clear();
        cin >> n;
        cin.ignore();

        for (int j = 0; j < n; j++){
            getline(cin, instrution);
            instrutions.push_back(instrution);

            p += makeMove(instrution, instrutions);
        }

        cout << p << endl;
    }
}