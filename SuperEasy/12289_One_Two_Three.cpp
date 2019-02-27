#include <iostream>
using namespace std;

int main(){
    int t;
    string w;

    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++){
        getline(cin, w); 
        if (w.size() == 3){
            if ((w[0] == 'o' && (w[1] == 'n' || w[2] == 'e')) || (w[1] == 'n' && w[2] == 'e'))
                cout << 1;
            else
                cout << 2;
        }else
            cout << 3;

        cout << endl;
    }
}