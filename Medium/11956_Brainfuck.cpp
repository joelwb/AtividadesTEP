#include <iostream>
using namespace std;

typedef unsigned char byte;

int main(){
    int t;

    cin >> t;

    for (int i = 0; i < t; i++){
        cin.ignore();
        byte mem[100] = {};
        string comand;
        long pointer = 0;

        cin >> comand;
        cout << "Case " << i+1 << ":";

        for (unsigned int j = 0; j < comand.size(); j++){
            if (comand[j] == '>') pointer++;
            else if (comand[j] == '<') pointer--;
            else if (comand[j] == '+') mem[pointer % 100]++;
            else if (comand[j] == '-') mem[pointer % 100]--;

            if (pointer == -1) pointer = 99;
        }
        
        for (int j = 0; j < 100; j++){
            printf(" %02X", mem[j]);
        }

        cout << endl;

    }
    

}