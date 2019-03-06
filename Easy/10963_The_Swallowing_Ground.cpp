#include <iostream>
using namespace std;

int main(){
    int n, W, y1, y2;
    string blank_line;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++){
        getline(cin, blank_line);

        bool yes = true;
        cin >> W;
        cin >> y1 >> y2;

        int gap = y1 - y2;

        for (int j = 0; j < W - 1; j++){
            cin >> y1 >> y2;
            if (gap != y1 - y2) yes = false;
        }

        if (yes) cout << "yes";
        else     cout << "no";

        cout << endl;

        if (i != n -1 ) cout << endl;
    }
}