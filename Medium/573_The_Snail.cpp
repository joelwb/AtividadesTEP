#include <iostream>
using namespace std;


int main(){
    int H, U, D, F;

    cin >> H >> U >> D >> F;

    while (H){
        bool hasSuccess = false;
        double fatigue = U * (F / 100.0);
        int i = 0;
        double currentHeight = 0;
        double currentU = U;

        while (currentHeight >= 0 && !hasSuccess){
            currentHeight += currentU;
            i++;

            if (currentHeight > H) hasSuccess = true;

            currentHeight -= D;
            currentU -= fatigue;
            if (currentU < 0) currentU = 0;
        }

        if (hasSuccess) cout << "success on day " << i;
        else cout << "failure on day " << i;

        cout << endl;

        cin >> H >> U >> D >> F;
    }
}