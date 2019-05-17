#include "function.h"

const int Vector::operator[](int index) const {
    return v[index];
}
int Vector::operator*(const Vector& a){
    int value = 0, i;
    for (i = 0; i < v_size; i++) {
        value += v[i] * a.v[i];
    }
    return value;
}
