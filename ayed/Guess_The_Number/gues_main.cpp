#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guess.hpp"
using namespace std;

int main() {
    srand(time(0));
    int secretnum = rand() % 100 + 1;
    int num{0}, intentos{0};
    bool esigual{0};
    cout << "Adivina el número \n Desde el 1 hasta el 100 " << endl;
    
    while (esigual == 0) {
    cout << "Cual crees que es?" << endl;
    cin >> num;
    if (is_grater(num, secretnum) == 0) {
        cout << "No, elige uno MAYOR" << endl;
        intentos++;
    }
    else if (is_grater(num, secretnum) == 1) {
        cout << "No, elige uno MENOR" << endl;
        intentos++;
    }
    else if ( num == secretnum ) {
        esigual = 1;
    }
    }
    cout << "SI!! \n Estaba pensando exactamente en el " << secretnum << " Muy bien" << endl;
    cout << "Necesitaste " << intentos << " intentos para adivinarlo, que crack" << endl;

}