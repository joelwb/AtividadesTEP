#include <iostream>
using namespace std;

int main(){
    string line;
    string newLine = "";
    bool flag = true; // Flag q indica se a próxima aspas está sendo aberta;
    while(getline(cin, line)){
        for (int i = 0; i < line.size(); i++){
            if (line[i] == '"'){
                if (flag) 
                    newLine += "``";
                else 
                    newLine += "''";
                
                flag = !flag;
            } else{
                newLine += line[i];
            }
        }
        cout << newLine << endl;
        newLine = "";
    }
}