#include <iostream>
using namespace std;
int main(){
    int k;
    int cont = 0;
    
    while(cin >> k && k){
        if (cont++) cout << endl;
        int set[k];

        for (int i = 0; i < k; i++){
            cin >> set[i];
        }


        for (int i = 0; i < k - 5; i++){
            for (int j = i + 1; j < k - 4; j++){
                for (int h = j + 1; h < k - 3; h++){
                    for (int a = h + 1; a < k - 2; a++){
                        for (int b = a + 1; b < k - 1; b++){
                            for (int c = b + 1; c < k; c++){
                                printf("%d %d %d %d %d %d\n", set[i], set[j], set[h], set[a], set[b], set[c]);
                            } 
                        } 
                    }   
                } 
            } 
        }
    }
}
