#include "lss_77_05.h"

int lss_75_05(int n, double *A, double *B, double *X, double *tmp) {
    double *maxElement;
    int rowOfMaxElement;

    for (int i = 0; i < n-1; ++i) {
        maxElement = MaxElementInColumn(i,i, n, A);
        rowOfMaxElement = FindOutRow(maxElement, n , A);
        Swap2Rows(i,rowOfMaxElement, n , A, B);
        ModuleGaussIteration( i,  i,  n, A,  B);
    }

    X[n-1] = B[n-1] / *getPointerByIndexes(n-1, n-1, n, A);

    for (int i = n - 2; i >= 0 ; --i) {
        for (int j = i + 1; j < n; ++j) {
            B[i]-= *getPointerByIndexes(i, j, n, A) * X[j];
        }
        X[i] = B[i] / *getPointerByIndexes(i, i, n, A);
    }
    return 0;
}


double *getPointerByIndexes(int i, int j, int n, double *Arr) {
    return Arr + i * n + j;
}

void Swap2Rows(int row_1, int row_2, int n, double *Arr, double *B) {
    double *R_1, *R_2;
    double tmp;
    for (int i = 0; i < n; i++) {
        tmp = *getPointerByIndexes(row_1, i, n, Arr);
        *getPointerByIndexes(row_1, i, n, Arr) = *getPointerByIndexes(row_2, i, n, Arr);
        *getPointerByIndexes(row_2, i, n, Arr) = tmp;
    }
    tmp = B[row_1];
    B[row_1] = B[row_2];
    B[row_2] = tmp;
}

double *MaxElementInColumn(int column, int SearchFrom, int n, double *Arr) {
    double *CurrentMax = getPointerByIndexes(SearchFrom, column, n, Arr);
    for (int i = SearchFrom; i < n; i++) {
        if (*CurrentMax < *getPointerByIndexes(i, column, n, Arr)) {
            CurrentMax = getPointerByIndexes(i, column, n, Arr);
        }
    }
    return CurrentMax;
}

int ModuleGaussIteration(int i, int j, int n, double *Arr, double *B) {
    //  i, j - индексы элемента в матрице А под которым мы зануляем весь столбец
    double divisor = *getPointerByIndexes(i, j, n, Arr);
    if (fabs(divisor) < 1e-9 ) return -1;
    for (int k = i + 1; k < n; ++k) {// цикл по строкам

        double element = *getPointerByIndexes(k, j, n, Arr);
        for (int l = 0; l < n; ++l) { // цикл по столбцам

            *getPointerByIndexes(k, l, n, Arr) -= *getPointerByIndexes(i, l, n, Arr) * element / divisor;

        }
        B[k] -= B[i] * element / divisor;
    }
    return 0;
}

int FindOutRow(double *value, int n, double *Arr){ // возвращает номер строки по указателю на элемент
    return (int)(value - Arr)/n;
}