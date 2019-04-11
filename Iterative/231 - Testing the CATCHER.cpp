#include <iostream>
#include <vector>

using namespace std;

int main(){
    int height, max_intercepted, i;
    vector<int> heights;
    i = 1;
    while (cin >> height && height != -1){
        heights.push_back(height);
        while(cin >> height && height != -1){
            heights.push_back(height);
        }
        max_intercepted = 0;

        int LIS[heights.size()];

        for (int i = 0; i < heights.size(); i++){
            LIS[i] = 1;
            for (int j = i - 1; j >= 0; j--){
                if (heights[j] >= heights[i] && LIS[j]+1 > LIS[i]) {
                    LIS[i] = LIS[j] + 1;
                }
            }

            max_intercepted = max_intercepted < LIS[i] ? LIS[i] : max_intercepted;
        }
        
        heights.clear();
        
        if (i != 1) cout << endl;
        cout << "Test #" << i++ << ":" << endl;
        cout << "  maximum possible interceptions: " << max_intercepted << endl;
    }
}