#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int N, last, now;
    string s;
    

    cout << "Lumberjacks:" << endl;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++){
        bool isOrdered = true;
        getline(cin, s);
        stringstream stream;
        stream << s;

        stream >> last;
        for (int j = 0; j < 9; j++){
            stream >> now;

            if (now <= last){
                isOrdered = false;
                break;
            }

            last = now;
        }

        if (isOrdered) {
            cout << "Ordered" << endl;
            continue;
        }

        isOrdered = true;

        stream.str("");
        stream << s;
        stream >> last;
        for (int j = 0; j < 9; j++){
            stream >> now;

            if (now >= last){
                isOrdered = false;
                break;
            }

            last = now;
        }

        if (isOrdered) {
            cout << "Ordered" << endl;
            continue;
        }else {
            cout << "Unordered" << endl;
        }
    }
}