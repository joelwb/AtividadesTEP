#include <iostream>
using namespace std;

int main(){
    int start, f, s, t;
    int sum;

    cin >> start >> f >> s >> t;

    while(start || f ||s || t ){
        sum = (40 + start - f) % 40;
        sum += (40 + s - f) % 40;
        sum += (40 + s - t) % 40;
        sum *= 9;

        cout << 1080 + sum << endl;
        cin >> start >> f >> s >> t;
    }
    
}