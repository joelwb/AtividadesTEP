#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;


int main(){
    int N, count;
    count = 1;
    string s;

    while(cin >> N){
        int S[N];

        for (int i = 0; i < N; i++){
            cin >> S[i];
        }

        long long result = 0;

        for (int i = 0; i < N; ++i){
            long long temp = 1;
            for (int j = i; j < N; ++j) {
                temp *= S[j];
                result = max(result, temp);
            }
        }
            

        cout << "Case #" << count << ": The maximum product is " << result << "." << endl << endl;
        count++;

        cin.ignore();
        getline(cin, s);
    }
}