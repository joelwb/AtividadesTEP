#include <iostream>
using namespace std;

int main(){
    int C1, C2, up, down;

    cin >> C1 >> C2;

    while (C1 != -1 && C2 != -1){
        up = abs(C1 - C2);

        if (C1 < C2) down = C1 + (100 - C2);
        else         down = C2 + (100 - C1);

        if (up > down) cout << down;
        else           cout << up;

        cout << endl;

        cin >> C1 >> C2;
    }
}
