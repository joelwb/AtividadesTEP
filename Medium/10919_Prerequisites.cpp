#include <iostream>
using namespace std;

bool in(int a[], int size, int n){
    for (int i = 0; i < size; i++){
        if (a[i] == n) return true;
    }

    return false;
}

int main(){
    int numCursos, numCateg;

    cin >> numCursos >> numCateg;

    while (numCursos){
        int a[numCursos];
        bool flag = true;

        for (int i = 0; i < numCursos; i++){
            cin >> a[i];
        }

        int c, r, codCurso;

        for (int i = 0; i < numCateg; i++){
            cin >> c >> r;
            int sum = 0;
            for (int j = 0; j < c; j++){
                cin >> codCurso;
                sum += (in(a, numCursos, codCurso)) ? 1 : 0;
            }

            if (sum < r) flag = false;
        }

        if (flag) cout << "yes";
        else      cout << "no";

        cout << endl;

        cin >> numCursos >> numCateg;
    }
}