#include <iostream>
using namespace std;

int main(){
    int T, L, W, H, count;

    count = 1;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "Case " << count << ": ";
        cin >> L >> W >> H;

        if (L > 20|| W > 20 || H > 20) cout << "bad";
        else cout << "good";

        cout << endl;
        count++;
    }
}