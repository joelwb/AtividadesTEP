#include <iostream>
using namespace std;

int main(){
    int duration, numRegs;
    double adiantamento, loan;

    cin >> duration >> adiantamento >> loan >> numRegs;

    while(duration > 0){
        double valorCar = loan + adiantamento;
        double valorLoan = loan;
        double parcel = loan / duration;
        int currentMonth, countMonth = 1;
        double depreciation;
        double dep[duration + 1];

        cin >> currentMonth >> depreciation;
        valorCar = valorCar * (1 - depreciation);

        for (int i = 0; i < numRegs - 1; i++){
            cin >> currentMonth >> depreciation;

            for (int j = currentMonth; j < duration; j++){
                dep[j] = depreciation;
            }
        }

        while (valorCar < valorLoan){
            valorLoan -= parcel;
            valorCar = valorCar * (1 - dep[countMonth]);

            countMonth++;
        }

        cout << countMonth-1 << " month";
		if (countMonth-1 != 1) cout << "s";
		cout << endl;

        cin >> duration >> adiantamento >> loan >> numRegs;
    }
    
}