#include <iostream>
#include <math.h>

using namespace std;

int q[225];

void calc_quadrados(){
    for (int i = 0; i < 255; i++){
        q[i] = i * i;
    }
}

int main(){
    int N, K;

    cin >> N;

    calc_quadrados();

    for (int i = 0; i < N; i++){
        cin >> K;
        bool flag = false;
        for (int j = 0; q[j] < K; j++){
            for (int k = 0; q[k] < K - q[j]; k++){
                int h = sqrt(K-q[j]-q[k]);
                if (q[j] + q[k] + q[h] == K) {
                    cout << j << " " << k << " " << h << endl;
                    flag = true;
                    break;
                }
            }

            if (flag) break;
        }

        if (!flag) cout << "-1" << endl;
    }
}