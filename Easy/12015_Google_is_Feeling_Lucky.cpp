#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int main(){
    int T, V, maxV;
    string url;
    vector<string> topUrls;

    cin >> T;

    for (int i = 0; i < T; i++){
        topUrls.clear();
        cout << "Case #" << i+1 << ":" << endl;

        cin >> url >> V;
        maxV = V;
        topUrls.push_back(url);

        for (int j = 0; j < 9; j++){
            cin >> url >> V;

            if (maxV == V) topUrls.push_back(url);
            else if (maxV < V){
                topUrls.clear();
                topUrls.push_back(url);
                maxV = V;
            }
        }
        
        for (unsigned int j = 0; j < topUrls.size(); j++){
            cout << topUrls[j] << endl;
        }
    }
}