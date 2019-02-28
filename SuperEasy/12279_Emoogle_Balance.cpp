#include <iostream>
using namespace std;

int main(){
    int t, X, count;
    count = 1;
    cin >> t;
    while (t != 0){
        cout << "Case " << count << ": ";
        int Y = 0;
        for (int i = 0; i < t; i++){
            cin >> X;
            if (X > 0) Y++;
            else Y--;
        }
        cout << Y << endl;
        
        cin >> t;
        count++;
    }
}