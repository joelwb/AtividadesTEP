#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int t, n;
vector<string> somas;


void backtrack(int x[], int first, int soma, string soma_str) {
    string result = (soma == 0) ? to_string(x[first]) : soma_str + "+" + to_string(x[first]);

    if (x[first] + soma > t) return;
    if (x[first] + soma == t && find(somas.begin(), somas.end(), result) == somas.end()) {
        somas.push_back(result);
    }
    else{
        for (int i = first+1; i < n; i++){
            backtrack(x, i, x[first] + soma, result);
        }
    }
}

int main(){
    while(cin >> t && t != 0){
        cin >> n;
        int x[n];

        for (int i = 0; i < n; i++){
            cin >> x[i];
        }

        somas.clear();

        for (int i = 0; i < n; i++){
            backtrack(x, i, 0, "");
        }

        cout << "Sums of " << t << ":" << endl;

        if (somas.size() == 0){
            cout << "NONE" << endl;
        }
        else {
            for (int i = 0; i < somas.size(); i++){
                cout << somas[i] << endl;
            }
        }
    }
}