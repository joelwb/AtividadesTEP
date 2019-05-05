#include <iostream>
#include <vector>

using namespace std;

int t, n, p;
bool flag;
vector<int> barras;

void backtrack(int i, int sum){
    if (sum > n) return;
    if (sum == n) {
        flag = true;
        return;
    }
    for (int j = i+1; j < p; j++){
        if (!flag){
            backtrack(j, sum + barras[j]);
        }
    }
}

int main(){
    int aux;

    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n >> p;
        flag = false;
        for (int j = 0; j < p; j++){
            cin >> aux;
            barras.push_back(aux);
        }

        backtrack(-1,0);
        
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}