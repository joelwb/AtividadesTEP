#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, query, count;
    count = 1;

    while(true){
        cin >> n;
        if (n == 0) break;

        int set[n];
        for (int i = 0; i < n; i++){
            cin >> set[i];
        }

        cin >> m;
        cout << "Case " << count << ":" << endl;


        for (int k = 0; k < m; k++){
            int closest = set[0]+ set[1];
            int distance = INT32_MAX;

            cin >> query;
            for (int i = 0; i < n; i ++){
                for (int j = 0; j < n; j++){
                    if (set[i] == set[j]) continue;

                    int newDist = abs((set[i] + set[j]) - query);
                    if (newDist < distance){
                        distance = newDist;
                        closest = set[i] + set[j];
                    }
                }
            }

            cout << "Closest sum to " << query << " is " << closest << "." << endl;
        }

        count++;
    }
}