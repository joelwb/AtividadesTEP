#include <iostream>
using namespace std;

int main(){
    int K, N, M, X, Y;
    cin >> K;

    while (K != 0){
        cin >> N >> M;

        for (int i = 0; i < K; i++){
            cin >> X >> Y;

            if (X == N || X == M || Y == N || Y == M)
                cout << "divisa";
            else if (X < N){
                if (Y > M)
                    cout << "NO";
                else
                    cout << "SO";
            }
            else{
                if (Y > M)
                    cout << "NE";
                else
                    cout << "SE";
            }

            cout << endl;
        }

        cin >> K;
    }
}