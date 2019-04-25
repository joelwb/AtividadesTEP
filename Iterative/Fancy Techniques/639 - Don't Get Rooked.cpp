#include <iostream>
#include <vector>
#include <string.h>
#include <utility>

using namespace std;

int size_board;
short board[4][4];
short max_qtd;


bool can_place(int r, int c,  vector<pair<short,short>> impedidos, vector<pair<short,short>> markeds){
    pair<short, short> ponto (r,c);
    bool impedido = find(impedidos.begin(), impedidos.end(), ponto) != impedidos.end();
    bool is_obstaculo = board[r][c];
    bools is_marked = find(markeds.begin(), markeds.end(), ponto) != markeds.end();
    return !(impedido || is_obstaculo || is_marked);
}

pair<short, short> next_ponto( vector<pair<short,short>> impedidos, vector<pair<short,short>> markeds){
    for (int r = 0; r < size_board; r++){
        for (int c = 0; c < size_board; c++){
            if (can_place(r,c, impedidos, markeds)){
                return make(r, c);
            } 
        }
    }
}

vector<pair<short,short>> mark_impedidos(int r, int c,  vector<pair<short,short>> impedidos){
    for (int i = r-1; i >= 0; i--){
        if (board[i][c]) break;
        impedidos.push_back(make_pair(i, c));
    }
    
    for (int i = r+1; i < size_board; i++){
        if (board[i][c]) break;
        impedidos.push_back(make_pair(i, c));
    }

    for (int i = c-1; i >= 0; i--){
        if (board[r][i]) break;
        impedidos.push_back(make_pair(r, i));
    }

    for (int i = c+1; i < size_board; i++){
        if (board[r][i]) break;
        impedidos.push_back(make_pair(r, i));
    }

    return impedidos;
}

void backtrack(int r, int c, vector<pair<short,short>> impedidos, vector<pair<short,short>> markeds){
    
    markeds.push(make_pair(r,c));
    impedidos = mark_impedidos(r, c, impedidos);
    pair<short, short> ponto = next_ponto(impedidos, markeds);
    backtrack(ponto.first, ponto.second, impedidos, markeds);
}


int main(){
    string row;

    while (cin >> size_board && size_board){
        max_qtd = 0;
        memset(board, 0, 16*(sizeof(short)));

        for (int i = 0; i < size_board; i++){
            cin >> row;
            for (int j = 0; j < size_board; j++){
                board[i][j] = row[j] == '.' ? 0 : 1;
            }
        }
        
        backtrack(0, 0, {}, {});
        
        cout << max_qtd << endl;
    }
}