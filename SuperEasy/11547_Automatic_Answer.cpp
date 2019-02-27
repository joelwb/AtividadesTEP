#include <iostream>
#include <string> 
using namespace std;

int main(){
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n;

        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;


        if (n > 10 && n < 10)
            cout << "0";
        else{
            string nStr = to_string(n);
            
            cout << nStr[nStr.size() - 2] << endl;
        }
    }
}