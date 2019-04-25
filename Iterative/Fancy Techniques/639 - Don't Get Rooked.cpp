#include <iostream>
#include <vector>
#include <string.h>
#include <utility>
#include <algorithm>

using namespace std;

int size_board;
short board[4][4];
short max_qtd;
bool flag;


bool can_place(int r, int c,  vector<pair<short,short>> impedidos, vector<pair<short,short>> markeds){
    pair<short, short> ponto (r,c);
    bool impedido = find(impedidos.begin(), impedidos.end(), ponto) != impedidos.end();
    bool is_obstaculo = board[r][c];
    bool is_marked = find(markeds.begin(), markeds.end(), ponto) != markeds.end();
    return !(impedido || is_obstaculo || is_marked);
}

pair<short, short> next_ponto( vector<pair<short,short>> impedidos, vector<pair<short,short>> markeds){
    for (int r = 0; r < size_board; r++){
        for (int c = 0; c < size_board; c++){
            if (can_place(r,c, impedidos, markeds)){
                return make_pair(r, c);
            } 
        }
    }
    return make_pair(-1,-1);
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

pair<short, short> next_possib(int r, int c, vector<pair<short,short>> impedidos, vector<pair<short,short>> markeds){
    while (r*c <= (size_board-1) * (size_board-1)){
        if (c+1 == size_board) {
            c = 0; r++;
            if (r == size_board) break;
        }else {
            c++;
        }
        
        if (can_place(r,c, impedidos, markeds)) {
            return make_pair(r,c);
        }
    }
    
    return make_pair(-1,-1);
}

void backtrack(int r, int c, vector<pair<short,short>> impedidos, vector<pair<short,short>> markeds, int qtd){
    
    markeds.push_back(make_pair(r,c));

    vector<pair<short,short>> new_impedidos = mark_impedidos(r, c, impedidos);
    pair<short, short> ponto = next_ponto(new_impedidos, markeds);
    if (ponto.first != -1){
        flag = true;
        backtrack(ponto.first, ponto.second, new_impedidos, markeds, qtd+1);
        
        markeds.erase(markeds.end() - 1);
        ponto = next_possib(r, c, impedidos, markeds);
        if (ponto.first != -1)
            backtrack(ponto.first, ponto.second, impedidos, markeds, qtd);
    } else {
        max_qtd = qtd+1 > max_qtd ? qtd+1 : max_qtd;
    }
}


int main(){
    string row;

    while (cin >> size_board && size_board){
        max_qtd = 0;
        flag = false;
        memset(board, 0, 16*(sizeof(short)));

        for (int i = 0; i < size_board; i++){
            cin >> row;
            for (int j = 0; j < size_board; j++){
                board[i][j] = row[j] == '.' ? 0 : 1;
            }
        }
        
        pair<short, short> ponto = next_ponto({},{});
        
        while (!flag && ponto.first != -1){
            backtrack(ponto.first, ponto.second, {}, {}, 0);
            ponto = next_possib(ponto.first, ponto.second, {}, {});
        }
        
        cout << max_qtd << endl;
    }
}