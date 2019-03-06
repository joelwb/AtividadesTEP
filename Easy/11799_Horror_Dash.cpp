#include <iostream>
using namespace std;

int main(){
    int T, N, c;

    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> N;
        int max = 0;
        for (int j = 0; j < N; j++){
            cin >> c;
            if (c > max) max = c;
        }

        cout << "Case " << i+1 << ": " << max << endl; 
    }
}