#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    while (n){
        cin.ignore();
        string line;
        int min = 2000001;
        int cont = 0;
        getline(cin, line);

        if (line.find_first_of('Z') != string::npos) {
            cout << 0 << endl;
        } else{
            int firstPosD = line.find_first_of('D');
            int firstPosR = line.find_first_of('R');
            char current = (firstPosD > firstPosR) ? 'R' : 'D';

            for (int i = 0; i < n; i++){
                cont++;
                if (line[i] == '.') continue;

                if (line[i] == 'D' && current == 'R'){
                    min = (min > cont) ? cont : min;
                } else if ((line[i] == 'R' && current == 'D')){
                     min = (min > cont) ? cont : min;
                }

                cont = 0;
                current = line[i];
            }

            cout << min << endl;
        }

        cin >> n;
    }
}