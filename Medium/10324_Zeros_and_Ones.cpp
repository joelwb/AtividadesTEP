#include <iostream>
using namespace std;


int main(){
    string zero_ones;
    int n, i, j, counter = 1;

    while(getline(cin, zero_ones)){
        cout << "Case " << counter << ":" << endl;

        cin >> n;
        for (int k = 0; k < n; k++){
            cin >> i >> j;

            if (i == j) cout << "Yes";
            else {
                string subS = (i < j) ? zero_ones.substr(i, j-i+1) : zero_ones.substr(j, i-j+1);

                char firstChar = subS[0];
                bool flag = true;
                for (unsigned int m = 1; m < subS.size(); m++){
                    if (subS[m] != firstChar) {
                        flag = false;
                        break;
                    }
                }

                if (flag) cout << "Yes";
                else      cout << "No";

            }

            cout << endl;
        }

        counter++;
        cin.ignore();
    }


}