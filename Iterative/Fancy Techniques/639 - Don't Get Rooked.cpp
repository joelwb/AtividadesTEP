#include <iostream>
#include <string.h>

using namespace std;

int size_board;
short board[4][4];
short placed_rocks[4][4];
short max_qtd;
short qtd;
short last_row_checked;

bool can_place(int r, int c){

    for (int i = r-1; i >= 0; i--){
        if (placed_rocks[i][c]) return false;
        if (board[i][c]) break;
    }
    
    for (int i = r+1; i < size_board; i++){
        if (placed_rocks[i][c]) return false;
        if (board[i][c]) break;
    }

    for (int i = c-1; i >= 0; i--){
        if (placed_rocks[r][i]) return false;
        if (board[r][i]) break;
    }

    return true;
}

void backtrack(int r, int c){
    if (r == size_board - 1){
        for (int i = 0; i < size_board; i++){
            if (board[r][i] == 0 && can_place(r, i)){
                placed_rocks[r][i] = 1;
                qtd++;
            }
        }
        last_row_checked = r;
    }else {
        for (int i = c; i < size_board; i++){

            if (board[r][i] == 0 && can_place(r, i)){
                placed_rocks[r][i] = 1;
                qtd++;
                if (last_row_checked > r+1 && r < size_board - 1)
                    backtrack(r+1,0);
                
            }
        }
        
        if (last_row_checked > r+1 && r < size_board - 1)
            backtrack(r+1,0);

        last_row_checked = r;
        if (qtd > max_qtd) max_qtd = qtd;
        
        if (c < size_board - 1){
            qtd = 0;
            for (int i = 0; i < r; i++){
                for (int j = 0; j < size_board; j++) 
                    if (placed_rocks[i][j]) qtd++;
            }
            
            for (int i = r; i < size_board; i++) memset(placed_rocks[i], 0, 4*(sizeof(short)));
            last_row_checked = r+1;
            backtrack(r, c+1);
        }
    }
}


int main(){
    string row;

    while (cin >> size_board && size_board){
        max_qtd = 0;
        qtd = 0;
        memset(placed_rocks, 0, 16*(sizeof(short)));
        memset(board, 0, 16*(sizeof(short)));
        last_row_checked = 4;
        for (int i = 0; i < size_board; i++){
            cin >> row;
            for (int j = 0; j < size_board; j++){
                board[i][j] = row[j] == '.' ? 0 : 1;
            }
        }
        
        backtrack(0, 0);
        
        cout << max_qtd << endl;
    }
}