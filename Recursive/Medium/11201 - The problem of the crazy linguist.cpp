#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<char, double> tableProb = {
    {'a', 12.53}, 
    {'b', 1.42},
    {'c', 4.68},
    {'d', 5.86},
    {'e', 13.68},
    {'f', 0.69},
    {'g', 1.01},
    {'h', 0.70},
    {'i', 6.25},
    {'j', 0.44},
    {'k', 0.0},
    {'l', 4.97},
    {'m', 3.15},
    {'n', 6.71},
    {'o', 8.68},
    {'p', 2.51},
    {'q', 0.88},
    {'r', 6.87},
    {'s', 7.98},
    {'t', 4.63},
    {'u', 3.93},
    {'v', 0.90},
    {'w', 0.02},
    {'x', 0.22},
    {'y', 0.90},
    {'z', 0.52}
};
char vogais[5];
char consoantes[21];
double sum;
int n, counter;

void extractLetters(){
    for (int i = 0; i < 5; i++) vogais[i] = "aeiou"[i];
    for (int i = 0; i < 21; i++) consoantes[i] = "bcdfghjklmnpqrstvwxyz"[i];
}

int find_pos(char c){
    for (int i = 0; i < 21; i++){
        if (consoantes[i] == c) return i;
    }

    return -1;
}

int count_char(char c, string s){
    int counter = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == c) counter++;
    }

    return counter;
}

double sbc(string s){
    double somatoria = 0;
    for (int i = 0; i < s.size(); i++){
        somatoria += (i+1) * tableProb[s[i]];
    }

    return somatoria;
}


void backtrack(int pos, string gener_word, int pos_inicial, int pos_final, double valor) {
    if (gener_word.size() == n){
        sum += valor;
        counter++;
    }else {
        if (pos % 2 == 0) {
            for (int i = 0; i < 5; i++){
                if (count_char(vogais[i], gener_word) < 2)
                    backtrack(pos+1, gener_word + vogais[i], 0, 21, valor + pos * tableProb[vogais[i]]);
            }        
        } else {
            for (int i = pos_inicial; i < pos_final; i++){
                if (count_char(consoantes[i], gener_word) < 2)
                    backtrack(pos+1, gener_word + consoantes[i], 0, 5, valor + pos * tableProb[consoantes[i]]);
            }  
        }
    }
}

int main(){
    extractLetters();
    
    int k;
    string s;
    
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; i++){
        getline(cin, s);
        double calc = sbc(s);
        int pos = find_pos(s[0]);
        n = s.size();

        sum = 0;
        counter = 0;
        backtrack(1, "", pos, pos + 1, 0);

        
        double media = sum / counter;
        if (calc < media) cout << "below" << endl;
        else cout << "above or equal" << endl;       
    }
}