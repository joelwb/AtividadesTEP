#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool is_divisible(int n, int d){
    return d % n == 0;
}

int main(){
    int k, x, y;
    string s;

    while (cin >> k){
        vector<string> contas;
        y = k+1;

        do{
            do {
                x = k*y;
                y++;
            }while(!is_divisible(y-k-1, x));
            
            x /= y-k-1;
            s = "1/" + to_string(k) + " = 1/" + to_string(x) + " + 1/" + to_string(y-1);
            contas.push_back(s);

        }while(y-1 != x);

        cout << contas.size() << endl;

        for (int i = 0; i <contas.size(); i++){
            cout << contas[i] << endl;
        }
    }
}