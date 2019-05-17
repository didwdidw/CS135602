#include "function.h"

Matrix Matrix::operator*(const Matrix &a) const{
    Matrix temp(size_row, a.size_col);
    int r, k, c;
    for (r = 0; r < size_row; r++) {
        for (c = 0; c < a.size_col; c++) {
            int value = 0;
            for (k = 0; k < size_col; k++) {
                value += arr[r][k] * a.arr[k][c];
            }
            temp.arr[r][c] = value;
        }
    }
    return temp;
}

Matrix Matrix::operator=(const Matrix &a) {
    int i;
    for (i = 0; i < size_row; i++) {
        delete [] arr[i];
    }
    delete []arr;

    size_row = a.get_size_row();
    size_col = a.get_size_col();
    arr = new int* [size_row];
    for (i = 0; i < size_row; i++) {
        arr[i] = a.get_row(i);
    }

    return *this;
}

Matrix MatrixChain::calc(int l, int r) const {
    if (l == r-1)
        return *arr[l];
    else
        return (*arr[l]) * calc(l+1, r);
}

