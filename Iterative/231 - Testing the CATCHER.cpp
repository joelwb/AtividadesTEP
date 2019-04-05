#include <iostream>
#include <vector>

using namespace std;

int main(){
    int height, last_height_intercepted, cont, i;
    i = 1;
    while (cin >> height && height != -1){
        cont = 1;
        last_height_intercepted = height;

        while(cin >> height && height != -1){
            if (height <= last_height_intercepted) cont++;
            last_height_intercepted = height;
        }
        cout << "Test #" << i << ":" << endl;
        cout << "  maximum possible interceptions: " << cont << endl << endl;
        i++;
    }
}