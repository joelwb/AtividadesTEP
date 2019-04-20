#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int,vector<int>> adjTable;
vector<int> verif;
vector<int> blackNodes;
vector<int> ans;
int m, n, k;

void paint(int node){
    if (node == n+1){
        if (blackNodes.size() >= ans.size()) ans = blackNodes;
        return;
    }

    if (find(verif.begin(), verif.end(), node) == verif.end()) verif.push_back(node);

    bool canBeBlack = true;

    for(int i = 0; i < adjTable[node].size(); i++){
        int adj = adjTable[node][i];
        bool isverif = find(verif.begin(), verif.end(), adj) != verif.end();
        bool isblack = find(blackNodes.begin(), blackNodes.end(), adj) != blackNodes.end();
        if (isverif && isblack){
            canBeBlack = false;
            break;
        }
    }

    if (canBeBlack) {
        blackNodes.push_back(node);
        paint(node + 1);
        blackNodes.erase(remove(blackNodes.begin(), blackNodes.end(), node), blackNodes.end());
    }
    paint(node + 1);
    verif.erase(remove(verif.begin(), verif.end(), node), verif.end());
}


int main(){
    cin >> m;

    for (int i = 0; i < m; i++){
        adjTable.clear();
        verif.clear();
        blackNodes.clear();
        ans.clear();
        cin >> n >> k;

        for (int j = 0; j < k; j++){
            int n1, n2;
            cin >> n1 >> n2;

            adjTable[n1].push_back(n2);
            adjTable[n2].push_back(n1);

        }

        paint(1);

        cout << ans.size() << endl;
        for (int j = 0; j < ans.size(); j++){
            cout << ans[j];
            if (j != ans.size()-1) cout << " ";
        }
        cout << endl;
    }
}