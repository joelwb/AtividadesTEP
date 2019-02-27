#include <iostream>
using namespace std;

int main(){
    int t, max, min, x;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++){
        cin >> n;

        max = 0;
        min = 99;
        for (int j = 0; j < n; j++){
            cin >> x;
            if (x > max)
                max = x;
            if (x < min)
                min = x;
        }

        cout << (max - min) * 2 << endl;
    }
}