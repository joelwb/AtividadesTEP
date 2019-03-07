#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

map<char, int> m;


int f(string s){
    int sum = 0;
    for (unsigned int i = 0; i < s.size(); i++){
        sum += m[(char) s[i]];
    }

    if (sum > 9) return f(to_string(sum));
    else return sum;
}

string limpaStr(string s){
    stringstream newS;
    for (unsigned int i = 0; i < s.size(); i++){
        if (isalpha(s[i])) newS << s[i];
    }

    return newS.str();
}

int main(){
    string nome1, nome2;

    for (int i = 0; i < 26; i++) m[(char) ('a' + i)] = i + 1;
    for (int i = 0; i < 10; i++) m[(char) ('0' + i)] = i;

    cout << fixed;
    cout << setprecision(2);

    while(getline(cin, nome1)){
        getline(cin, nome2);

        transform(nome1.begin(), nome1.end(), nome1.begin(), ::tolower);
        transform(nome2.begin(), nome2.end(), nome2.begin(), ::tolower);

        int aux1 = f(limpaStr(nome1));
        int aux2 = f(limpaStr(nome2));
        double ratio = (aux1 > aux2) ? (double) aux2/aux1 : (double) aux1/aux2;

        cout << ratio * 100 << " %"<<  endl; 
    }
}