#include <iostream>

using namespace std;

bool change(char cur, char c1, char c2){
    if(cur == 'x' && c1 == '-') return true;
    if(cur == 'y' && c2 == 'y' && c1 == '+') return true;
    if(cur == 'z' && c2 == 'z' && c1 == '+') return true;
    return false;
}

int main(){
    int L;
    string s;
    
    cin >> L;

    while(L){
        int sinal = 1;
        char c = 'x';
        
        for(int i = 0;i < L - 1;i++){
            cin >> s;
            if(s[0] == 'N') continue;
            
            if(change(c,s[0],s[1])) sinal = -sinal;
            
            if(c == 'x') c = s[1];
            else if (c == s[1]) c = 'x';
        }

        char sinalStr = sinal == 1 ? '+' : '-';
        cout << sinalStr << c << endl;

        cin >> L;
    }
}