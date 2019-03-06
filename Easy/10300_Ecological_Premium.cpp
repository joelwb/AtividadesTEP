#include <iostream>
using namespace std;

int main(){
    int n, f, sizeFarm, numAnimals, envFriend = 0;
    
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> f;
        long long sum = 0;
        for (int j = 0; j < f; j++){
            cin >> sizeFarm >> numAnimals >> envFriend;

            sum += (long long) sizeFarm * envFriend;
        }
        cout << sum << endl;
    }
}