#include <iostream>
#include <vector>
using namespace std;

int main(){
    string music[] = {"Happy", "birthday", "to", "you", 
                    "Happy", "birthday", "to", "you", 
                    "Happy", "birthday", "to", "Rujia", 
                    "Happy", "birthday", "to", "you"};

    vector<string> people;
    string person;
    int T;

    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++){
        getline(cin,person);
        people.push_back(person);
    }

    int rep = (T % 16 == 0) ? T / 16 : (T / 16) + 1;

    int cont = 0;
    for (int i = 0; i < rep; i++){
        for (int j = 0; j < 16; j++){
            cout << people[cont % T] << ": " << music[j] << endl;
            cont++;
        }
    }
}