#include <map> 
#include <iostream>
using namespace std;

int main(){
    string S;
    map<string, string> m = 
    {
        {"HELLO", "ENGLISH"},
        {"HOLA","SPANISH"},
        {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"} 
    };

    getline(cin, S);
    int i = 1;
    while(S != "#"){
        cout << "Case " << i << ": ";

        if (m.find(S) == m.end())
            cout << "UNKNOWN" ;
        else
            cout << m[S];
        
        cout << endl;
        getline(cin, S);
        i++;        
    }
        
}