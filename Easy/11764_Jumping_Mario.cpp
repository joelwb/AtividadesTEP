#include <iostream>
using namespace std;

int main(){
    int T, N, newH, oldH;

    cin >> T;
    for (int i = 0; i < T; i++){
        int lowCounter = 0;
        int highCounter = 0;
        cin >> N;
        cin >> oldH;
        for (int j = 0; j < N - 1; j++){
            cin >> newH;
            if (newH > oldH)      highCounter++;
            else if (newH < oldH) lowCounter++;

            oldH = newH;
        }

        cout << "Case " << i+1 << ": " << highCounter << " " << lowCounter << endl; 
    }
}