#include <iostream>

using namespace std;

int m, n;

int espacosLivres(int matriz[], int j){
    if (matriz[j] == 1) return 0;

    int qtd = 1;
    for (int k = j + 1; k < n; k++) {
        if (matriz[k] == 0) qtd++;
        else break;
    }

    return qtd;
}

int main(){

    while (cin >> m >> n && m != 0 && n != 0){
        int matrizIn[m][n]; 
        int matrizDist[m][n];
        int qtdMax = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) cin >> matrizIn[i][j];
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)  {
                matrizDist[i][j] = espacosLivres(matrizIn[i], j);
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)  {
                int qtdMaxLocal = 0;
                int menorEspacoVazio = n;
                for (int k = i; k < m; k++){
                    if (matrizDist[k][j] < menorEspacoVazio){
                        menorEspacoVazio = matrizDist[k][j];
                    }

                    if (qtdMaxLocal < menorEspacoVazio * (k - i + 1)){
                        qtdMaxLocal = menorEspacoVazio * (k - i + 1);
                    }
                }
                
                qtdMax = (qtdMax < qtdMaxLocal) ? qtdMaxLocal : qtdMax;
            }
        }

        cout << qtdMax << endl;
    }
}