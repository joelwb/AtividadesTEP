#include <iostream>
#include <map>
using namespace std;


int main(){
    int n, m, c, count;
    
    cin >> n >> m >> c;
    count = 1;
    while (n && m && c){
        int ci[n+1];
        map<int, bool> mapT;
        int sum = 0;
        int maxConsume = 0;

        cout << "Sequence " << count << endl;

        for (int i = 1; i <= n; i++){
            cin >> ci[i];
            mapT[i] = false;
        }

        int device;

        for (int i = 0; i < m; i++){
            cin >> device;
            mapT[device] = !mapT[device];
            sum += (mapT[device]) ? ci[device] : - ci[device];
            if (maxConsume < sum) maxConsume = sum;
            if (sum > c) {
                for (int j = i+1; j < m; j++) cin >> device;
                break;
            }
        }

        if (sum > c) cout << "Fuse was blown.";
        else         cout << "Fuse was not blown." << endl << "Maximal power consumption was " << maxConsume << " amperes.";

        cout << endl << endl;
        cin >> n >> m >> c;

        count++;
    }
}