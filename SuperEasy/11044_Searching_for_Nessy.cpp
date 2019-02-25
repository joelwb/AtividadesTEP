#include <iostream>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    int n, m;
    for (int i = 0; i < testCases; i++){
        cin >> n >> m;
        cout << (n/3) * (m/3) << endl;
    }
}