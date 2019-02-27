#include <iostream>
using namespace std;

int main(){
    int t, n1, n2, n3;
    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n1 >> n2 >> n3;

        cout << "Case " << i+1 << ": ";

        if ((n1 > n2 && n2 > n3 && n1 > n3) || (n3 > n2 && n2 > n1 && n3 > n1))
            cout << n2;
        else if ((n1 > n2 && n1 < n3) || (n1 > n3 && n1 < n2))
            cout << n1;
        else
            cout << n3;

        cout << endl;
    }
}