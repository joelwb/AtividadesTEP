#include <iostream>

using namespace std;

long long valores[1000000], soma[1000000];

void calc(){
    valores[3] = 0;
    soma[3] = 0;

    int x;
    for (int i = 0; i < 1000000; i++){
        if (i%2 == 0) x++;

        valores[i] = valores[i-1] + x;
        soma[i] = soma[i-1] + valores[i];
    }
}

int main(){
    int n;

    while(cin >> n && n >= 3){
        cout << soma[n] << endl;
    }
}