#include <iostream>
using namespace std;

int main(){
    int count;
    string word;

    count = 1;
    getline(cin, word);
    while (word != "*"){
        cout << "Case " << count << ": ";
        
        if (word == "Hajj") cout << "Hajj-e-Akbar";
        else cout << "Hajj-e-Asghar";

        cout << endl;

        getline(cin, word);

        count++;
    }
}