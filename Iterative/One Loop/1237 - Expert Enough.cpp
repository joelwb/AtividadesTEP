#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct valor{
    int L;
    int H;
};

int main(){
    int T, D, L, H, Q, P;
    string M;

    

    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> D;
        map<string, valor> marcas;

        for (int j = 0; j < D; j++){
            cin >> M >> L >> H;
            valor V;
            V.L = L;
            V.H = H;
            marcas[M] = V;
        }

        cin >> Q;

        for (int j = 0; j < Q; j++){
            cin >> P;
            string melhor_marca = "";
            for (auto &marca : marcas){
                if (marca.second.H >= P && marca.second.L <= P){
                    melhor_marca = melhor_marca == "" ? marca.first : "UNDETERMINED";
                }
            }
            
            melhor_marca = melhor_marca == "" ? "UNDETERMINED" : melhor_marca;
            cout << melhor_marca << endl;
        }
        
        cout << endl;
    }
}

