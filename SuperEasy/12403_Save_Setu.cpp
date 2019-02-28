#include <iostream>
using namespace std;

int main(){
    int T, K, amount = 0;
    string word;


    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> word;
        
        if (word == "donate"){
            cin >> K;
            amount += K;
        } else {
            cout << amount << endl;
        }

    }
}