#include <iostream>

using namespace std;

int main(){
    int N;

    while (cin >> N && N != 0){
        int bets[N];
        for (int i = 0; i < N; i++){
            cin >> bets[i];
        }

        int max = 0;
        int aux = 0;

        for (int i = 0; i < N; i++){
            aux += bets[i];
            max = (aux > max) ? aux : max;
            aux = (aux < 0) ? 0 : aux;
        }

        if (max > 0) cout << "The maximum winning streak is " << max << "." << endl;
        else cout << "Losing streak." << endl;
    }
}