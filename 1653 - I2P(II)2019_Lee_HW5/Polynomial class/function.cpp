#include"function.h"
#include <string.h>
using namespace std;

Polynomial::Polynomial(){
    greatestPower = 0;
    coefficients[101] = {0};
}

Polynomial::Polynomial(const int a, const int b[]){
    greatestPower = a;
    int i;
    memset(coefficients, 0, sizeof(coefficients));
    for (i = 0; i <= a; i++){
        coefficients[i] = b[i];
    }
}

Polynomial Polynomial::add( const Polynomial a) const{
    int i, coe[101] = {0}, greatest = 0;
    for (i = 0; i < 101; i++) {
        coe[i] = coefficients[i] + a.coefficients[i];
    }
    if (greatest < greatestPower) greatest = greatestPower;
    if (greatest < a.greatestPower) greatest = a.greatestPower;
    Polynomial tmp(greatest, coe);
    return tmp;
}

Polynomial Polynomial::subtract( const Polynomial a) const{
    int i, coe[101] = {0}, greatest = 0;
    for (i = 0; i < 101; i++)
        coe[i] = coefficients[i] - a.coefficients[i];

    greatest = 0;
    if (greatest < greatestPower)
        greatest = greatestPower;
    if (greatest < a.greatestPower)
        greatest = a.greatestPower;
    Polynomial tmp(greatest, coe);
    return tmp;
}

Polynomial Polynomial::multiplication( const Polynomial a) const{
    int i, j, coe[101] = {0}, greatest = greatestPower + a.greatestPower;
    for (i = 0; i <= greatestPower; i++){
        for (j = 0; j <= a.greatestPower; j++){
            coe[i+j] += coefficients[i] * a.coefficients[j];
        }
    }
    Polynomial tmp(greatest, coe);
    return tmp;
}

void Polynomial::output() const{
    int i;
    for (i = greatestPower; i > 0; i--){
        cout << coefficients[i] << " ";
    }
    cout << coefficients[0];
}
