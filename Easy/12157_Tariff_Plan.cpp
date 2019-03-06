#include <iostream>
using namespace std;

int calcCharge(int sec, int rate){
    int rest = sec % rate;
    int x = (sec - rest) / rate;

    if (rate > 0) return x + 1;
    else          return x;
}

int main(){
    int T, N, duration;

    cin >> T;

    for (int i =0; i < T; i++){
        cout << "Case " << i+1 << ": ";

        cin >> N;
        int sumMile = 0;
        int sumJuice = 0;
        for (int j = 0; j < N; j++){
            cin >> duration;

            sumMile += calcCharge(duration, 30) * 10;
            sumJuice += calcCharge(duration, 60) * 15;
        }

        if (sumMile > sumJuice)       cout << "Juice " << sumJuice;
        else if (sumMile < sumJuice)  cout << "Mile " << sumMile;
        else                    cout << "Mile Juice " << sumMile;

        cout << endl;
    }

}

