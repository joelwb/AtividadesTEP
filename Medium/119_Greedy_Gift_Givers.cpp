#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main(){
    int numAmigos, valor, qtdGift;
    string nome;

    cin >> numAmigos;

    while(true){
        map<string, int> map;
        vector<string> nomes;

        for (int i = 0; i < numAmigos; i++){
            cin >> nome;
            nomes.push_back(nome);
            map[nome] = 0;
        }

        for (int i = 0; i < numAmigos; i++){
            cin >> nome >> valor >> qtdGift;

            if (qtdGift != 0) map[nome] -= qtdGift * (valor / qtdGift);

            for (int j = 0; j < qtdGift; j++){
                cin >> nome;
                map[nome] += valor / qtdGift;
            }
        }

        for (unsigned int i = 0; i < nomes.size(); i++){
            cout << nomes[i] << " " << map[nomes[i]] << endl;
        }

        if(cin>>numAmigos) cout << endl;
        else break;
    }
}