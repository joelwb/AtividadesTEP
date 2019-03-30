#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T, n;
    
    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> n;
        int A[n];

        for (int j = 0; j < n; j++){
            cin >> A[j];
        }

        int sum = 0;
        for (int j = 0; j < n-1; j++){
            int sale = A[j+1];
            int count = 0;
            for (int g = 0; g < j+1; g++){
                if (sale >= A[g]) count++;
            }

            sum += count;
        }

        cout << sum << endl;
    }
}