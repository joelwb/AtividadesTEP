#include <iostream>   
#include <sstream> 
using namespace std;

int main(){
    int N, B, H, W;
    int p;
    while (cin >> N >> B >> H >> W){
        long minp = 10001 * 200; /*valor acima do max possivel*/
        for (int i = 0; i < H; i++){
            cin >> p;
            cin.ignore();

            string nBeds;
            getline(cin, nBeds);
            stringstream s;
            s << nBeds;

            if (p * N > B) continue;

            int beds;
            bool hasSufficient = false;
            for (int j = 0; j < W; j++){
                s >> beds;
                if (beds > N) {
                    hasSufficient = true;
                    break;
                }
            }

            if (hasSufficient && minp > p * N) {
                minp = p * N;
            }
        }

        if (minp < 10001 * 200) cout << minp;
        else                    cout << "stay home";

        cout << endl;
    }
}