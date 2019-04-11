#include <iostream>
#include <iomanip>

using namespace std;

int rc[8], pts[8][8], initialR, initialC, max_score;

bool can_place(int r, int c){
    for (int ant = 0; ant < c; ant++){
        if (rc[ant] == r || abs(rc[ant] - r)  == abs(ant - c)) return false;
    }

    return true;
}

void run(int c){
    if (c == 8 && rc[initialC] == initialR){
        int sum = 0;
        for (int i = 0; i < 8; i++){
            sum += pts[rc[i]][i];
        }

        if (sum > max_score) max_score = sum;
    }

    for (int r = 0; r < 8; r++){
        if (can_place(r, c)){
            rc[c] = r;
            run(c + 1);
        }
    }
}

int main(){
    int k;
    cin >> k;


    for (int i = 0; i < k; i++){
        for (int j = 0; j < 8; j++) {
            for (int h = 0; h < 8; h++){
                cin >> pts[j][h];
            }
        }
        
        max_score = - 1;

        for (int j = 0; j < 8; j++) {
            for (int h = 0; h < 8; h++){
                initialR = j;
                initialC = h;
                run(0);
            }
        }

        cout << setw(5) << max_score << endl;
    }
}