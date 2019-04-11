#include <iostream>
#include <iomanip>

using namespace std;

int rc[8], initialR, initialC, candidato;

bool can_place(int r, int c){
    for (int ant = 0; ant < c; ant++){
        if (rc[ant] == r || abs(rc[ant] - r)  == abs(ant - c)) return false;
    }

    return true;
}

void run(int c){
    if (c == 8 && rc[initialC] == initialR){
        cout << setw(2) << candidato++ << "     ";
        for (int j = 0; j < 8; j++) cout << " " << rc[j] + 1;
        cout << endl;
    }

    for (int r = 0; r < 8; r++){
        if (can_place(r, c)){
            rc[c] = r;
            run(c + 1);
        }
    }
}

int main(){
    int TC;
    string lixo;
    cin >> TC;


    for (int i = 0; i < TC; i++){
        candidato = 1;
        cin.ignore();
        getline(cin, lixo);
        cin >> initialR >> initialC;
        initialC--; initialR--;

        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl;
        cout << endl;
        run(0);
        if (i != TC - 1) cout << endl;
    }
}