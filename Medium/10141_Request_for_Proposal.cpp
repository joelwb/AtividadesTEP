#include <iostream>
#include <float.h>
using namespace std;


int main(){
    int n, p, k = 1;
    string req;

    cin >> n >> p;

    while (n && p){
        cin.ignore();
        double bestCompilice = 0;
        double bestPrice = DBL_MAX;
        string bestName;

        for (int i = 0; i < n; i++) getline(cin, req);

        for (int i = 0; i < p; i++){
            string nameProp;
            double price;
            int r;

            getline(cin, nameProp);
            cin >> price >> r;

            double compilance = (double) r / p;

            if (compilance > bestCompilice || (compilance == bestCompilice && price < bestPrice)){
                bestCompilice = compilance;
                bestPrice = price;
                bestName = nameProp;
            }

            cin.ignore();

            for (int j = 0; j < r; j++) getline(cin, req);
        }

        cout << "RFP #" << k << endl;
        cout << bestName << endl;

        k++;
        cin >> n >> p;
        if (n && p) cout << endl;
    }
}