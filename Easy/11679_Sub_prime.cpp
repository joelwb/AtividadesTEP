#include <iostream>
using namespace std;

int main(){
    int B, N, D, C, V;

    cin >> B >> N;

    while(B && N){
        int R[B];
        for (int i = 0; i < B; i++){
            cin >> R[i];
        }

        for (int i = 0; i < N; i++){
            cin >> D >> C >> V;

            R[D -1] -= V;
            R[C -1] += V;
        }

        bool canPay = true;

        for (int i = 0; i < B; i++){
            if (R[i] < 0) {
                canPay = false;
                break;
            }
        }

        if (canPay) cout << "S";
        else        cout << "N";

        cout << endl;

        cin >> B >> N;
    }
}