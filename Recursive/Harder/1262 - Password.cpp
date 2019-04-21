#include <iostream>
#include <string.h>
#include <string>     
#include <vector> 
#include <algorithm>

using namespace std;

char grid1[5][6];
char grid2[5][6];
string passK;
int counter, k;

int cmpfunc( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

void backtrack(int i, string pass){
    if (k == counter) return;
    
    if (i == 5) {

        if (binary_search(grid2[0], grid2[0] + 6, pass[0]) &&
            binary_search(grid2[1], grid2[1] + 6, pass[1]) &&
            binary_search(grid2[2], grid2[2] + 6, pass[2]) &&
            binary_search(grid2[3], grid2[3] + 6, pass[3]) &&
            binary_search(grid2[4], grid2[4] + 6, pass[4])){
                passK = pass;
                counter++;
            }
            
    }
    else {
        for (int h = 0; h < 6; h++)
            if (k != counter){
                if (h != 0 && grid1[i][h] == grid1[i][h-1]) continue;
                backtrack(i+1, pass+grid1[i][h]);
            }
    }
}

int main(){
    int t;

    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> k;
        string row;
        counter = 0;

        for (int j = 0; j < 6; j++){
            cin >> row;

            for (int h = 0; h < 5; h++){
                grid1[h][j] = row[h];
            }
        }

        for (int j = 0; j < 5; j++) sort(grid1[j], grid1[j] + 6);

        
        for (int j = 0; j < 6; j++){
            cin >> row;

            for (int h = 0; h < 5; h++){
                grid2[h][j] = row[h];
            }
        }

        for (int j = 0; j < 5; j++) sort(grid2[j], grid2[j] + 6);

        backtrack(0, "");
        
        if (k > counter) 
            cout << "NO";
        else 
            cout << passK;
            
        cout << endl;
    }
}